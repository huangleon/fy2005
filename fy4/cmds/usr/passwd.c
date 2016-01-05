// passwd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;

        if( me != this_player(1) ) return 0;

        ob = me->query_temp("link_ob");
        if( !ob ) return 0;
        while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

        write("╬к┴╦░▓╚л╞Ё╝√гм╟ы╧╚╩ф╚ы─·╘н└┤╡─├▄┬ыг║");
        input_to("get_old_pass", 1, ob);
        return 1;
}

private void get_old_pass(string pass, object ob)
{
        string old_pass;

        write("\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write("├▄┬ы┤э╬єгб\n");
                return;
        }
        write("╟ы╩ф╚ы╨┬╡─├▄┬ыг║");
        input_to("get_new_pass", 1, ob );
}

private void get_new_pass(string pass, object ob)
{
	if(!LOGIN_D->check_legal_password(ob,pass))
	return ;
        write("\n╟ы╘┘╩ф╚ы╥╗┤╬╨┬╡─├▄┬ыг║");
        input_to("confirm_new_pass", 1, ob, crypt(pass,0));
}

private void confirm_new_pass(string pass, object ob, string new_pass)
{
        write("\n");
        if( crypt(pass, new_pass)!=new_pass ) {
                write("╢╘▓╗╞Ёгм─·╩ф╚ы╡─├▄┬ы▓в▓╗╧р═мгм╝╠╨°╩╣╙├╘н└┤╡─├▄┬ыбг\n");
                return;
        }
        seteuid(getuid());
        if( !ob->set("password", new_pass) ) {
                write("├▄┬ы▒ф╕№╩з░▄гб\n");
                return;
        }

        ob->save();
        write("├▄┬ы▒ф╕№│╔╣жбг\n");
}

int help(object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	passwd[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю┐╔╥╘╨▐╕──у╡─╚╦╬я├▄┬ыбг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
HELP
    );
    return 1;
}
 
