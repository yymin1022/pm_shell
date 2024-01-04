/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pm_shell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:37:39 by sangylee          #+#    #+#             */
/*   Updated: 2024/01/04 16:39:01 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PM_SHELL_H
# define PM_SHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/history.h>
# include <readline/readline.h>

//SECTION - lexical_analysis
/*NOTE 
	TOKEN_TYPE_CHUNK,// 해석될 여지가 아직 존재하는 단계
	TOKEN_TYPE_ARGV,// 더이상 해석할 수 없는 단계
	TOKEN_TYPE_SPACE,// 빈칸
	TOKEN_TYPE_PIPELINE,// 파이프
	TOKEN_TYPE_REDIRECTION// 리다이렉션
*/
typedef enum e_token_type
{
	TOKEN_TYPE_CHUNK,
	TOKEN_TYPE_ARGV,
	TOKEN_TYPE_SPACE,
	TOKEN_TYPE_PIPELINE,
	TOKEN_TYPE_REDIRECTION
}t_token_type;

/*NOTE  
	type: 해당 토큰의 타입
	str: 해당 토큰의 문자열
	next: 다음 토큰을 가리킴
*/
typedef struct s_token
{
	t_token_type	type;
	char			*str;
	struct s_token	*next;
}t_token;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

t_token	*token_createnew(char *token_str, t_token_type token_type);
void	token_pushback(t_token **lst, t_token *new);
void	token_list_delfront(t_token **token_list);

void	lexical_analysis(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);

#endif
