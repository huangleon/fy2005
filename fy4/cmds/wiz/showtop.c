// Silencer@fengyun workgroup	June.2005

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string output;
	object *ob;
	int i;
	
	seteuid(getuid());
	
	if (arg == "-refresh"){
		ob = users();	
		for (i=0;i<sizeof(ob);i++) {
			if (!ob[i] || !objectp(ob[i])) continue;
			if (!(i%10))
				reset_eval_cost();
			STATUS_D->compare_status(ob[i]);
		}
		write("╣▓╝╞"+ sizeof(ob)+"╕Ў╢╘╧єгм╕№╨┬═ъ▒╧бг\n");
		return 1;
	}
		
	if (arg == "-rich")
	{
		output = STATUS_D->show_rich();
		me->start_more("", output, 0);		
	}	
	else if (arg == "-riddle")
	{
		output = STATUS_D->show_riddle();
		me->start_more("", output, 0);		
	}
	else {
		output = STATUS_D->show_top();
        me->start_more("", output, 0);
    }
    return 1;
}

int help(object me)
{
write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	showtop [<▓╬╩¤> .... ][0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m  
╒т╕Ў╓╕┴ю╧╘╩╛│ЎTOP═ц╝╥╡─╜°│╠╦┘╢╚бг

showtop 		╧╘╩╛top15 ╛н╤щ╓╡╡─═ц╝╥
showtop -riddle:	╧╘╩╛top15 ╜т├▄╡─═ц╝╥
showtop -rich:	╧╘╩╛top15 ┤ц┐ю╡─═ц╝╥

showtop -refresh ╟┐╓╞╧╡═│╕№╨┬╡▒╟░╘┌╧▀═ц╝╥╡─╝═┬╝ги║─╖╤╫╩╘┤гй

╫вг║╕├╩¤╛▌└┤╘┤╙┌╡╟┬╜║══╦│Ў╩▒╡─╝═┬╝бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
HELP
    );
    return 1;
}
