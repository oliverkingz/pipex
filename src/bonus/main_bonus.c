/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 02:49:53 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/25 21:06:06 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	int		status;

	if (argc < 5)
		(ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2), exit(1));
	check_args(argc, argv);
	init_struct(argc, argv, &pipex);
	if (argc < 6 && pipex.here_doc == true)
	{
		ft_putstr_fd("Usage: ./pipex here_doc LIMITER cmd1 cmd2 outfile\n", 2);
		exit(1);
	}
	check_open_files(argc, argv, &pipex);
	init_pipes(&pipex);
	status = my_pipex(argv, envp, &pipex);
	return (WEXITSTATUS(status));
}
