/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:02:34 by yonyoo            #+#    #+#             */
/*   Updated: 2024/01/20 18:40:51 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../pm_shell.h"

static void	print_env(char *key, char *val)
{
	printf("%s=%s\n", key, val);
}

int cmd_env(t_env *env_list)
{
	while (env_list)
	{
		print_env(env_list->key, env_list->value);
		env_list = env_list->next;
	}
	return (1);
}