/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:44:59 by sangylee          #+#    #+#             */
/*   Updated: 2024/01/21 16:28:44 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analysis.h"

void	handle_space(t_token **token_list)
{
	t_token	**head;
	t_token	*cur;

	head = token_list;
	cur = *head;
	while (cur)
	{
		if (cur->type == TOKEN_TYPE_SPACE)
			cur = token_delete(head, cur);
		cur = cur->next;
	}
}

void	handle_arg(t_token **token_list)
{
	t_token	**head;
	t_token	*cur;
	t_token	*next;
	char	*res;

	head = token_list;
	cur = *head;
	if (cur->next == 0)
		return ;
	while (cur)
	{
		next = cur->next;
		if (next && cur->type == TOKEN_TYPE_ARGV
			&& next->type == TOKEN_TYPE_ARGV)
		{
			res = ft_strjoin(cur->str, next->str);
			free(cur->str);
			free(next->str);
			cur->str = res;
			cur->next = next->next;
			free(next);
		}
		else
			cur = cur->next;
	}
}

void	handle_chunk(t_token **token_list)
{
	t_token	**head;
	t_token	*cur;

	head = token_list;
	cur = *head;
	while (cur)
	{
		if (cur->type == TOKEN_TYPE_CHUNK)
		{
			if (cur->str[0] != '\0')
				cur->type = TOKEN_TYPE_ARGV;
			else
				cur = token_delete(head, cur);
		}
		cur = cur->next;
	}
}

t_token	*lexical_analysis(t_info *info, char *s)
{
	t_token	*token_list;

	token_list = token_createnew(s, TOKEN_TYPE_CHUNK);
	handle_heredoc(info, token_list);
	handle_quote(info, token_list);
	handle_env(info, token_list);
	handle_seperator(token_list, " ");
	handle_seperator(token_list, "|");
	handle_seperator(token_list, "<<");
	handle_seperator(token_list, ">>");
	handle_seperator(token_list, "<");
	handle_seperator(token_list, ">");
	handle_chunk(&token_list);
	handle_arg(&token_list);
	handle_space(&token_list);
	return (token_list);
}
