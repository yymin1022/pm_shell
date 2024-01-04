/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:44:59 by sangylee          #+#    #+#             */
/*   Updated: 2024/01/04 15:05:37 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pm_shell.h"

void	lexical_analysis(char *str)
{
	t_token	*token_list;

	token_list = token_createnew(str, TOKEN_TYPE_CHUNK);
	while (token_list)
	{
		printf("%s\n", token_list->str);
		token_list = token_list->next;
	}
}
