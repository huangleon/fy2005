// chpasswd.c
// add by Karry@FY3

#include <login.h>;
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob,link_ob;
        string id,password;
        if(!arg||sscanf(arg,"%s %s",id,password)!=2)
                return notify_fail("╙├╖и:chpasswd ID ╨┬├▄┬ы\n╟ы╔ў╙├┤╦╓╕┴югб\n");
        ob=find_player(id);
        if(!ob)
        {
        ob = new(LOGIN_OB);
        ob->set("id",id);
    	
        if( !ob->restore() )
                return notify_fail("├╗╙╨╒т╕Ў═ц╝╥бг\n");
 
        else
                {                                    
           ob->set("password",crypt(password,0));
           tell_object(me, "═ц╝╥" + ob->query("id") + "("+ob->query("name")
                     + ")╡─├▄┬ы╥╤╛н╕№╕─╬кг║"+password+"бг\n");
 
                    log_file( "changepw", sprintf("%s %s(%s)╨▐╕─┴╦%s(%s)╡─├▄┬ы\n",
                ctime(time()), me->query("name"), me->query("id"),
                ob->query("name"), ob->query("id")));
           ob->save();
           destruct(ob);
           return 1;
                }
        }
        link_ob=ob->query_temp("link_ob");
        if(link_ob)
        {
                link_ob->set("password",crypt(password,0));
                link_ob->save();
                tell_object(me, "═ц╝╥" + ob->query("id") + "("+ob->query("name")
                        + ")╡─├▄┬ы╥╤╛н╕№╕─╬кг║"+password+"бг\n");
                return 1;
        }
        else
                return notify_fail("┤э╬єбг╬▐╖и╜°╨╨╨▐╕─бг\n");
        return 1;
}


int help(object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	chpasswd ID ╨┬├▄┬ы[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю┐╔╥╘╨▐╕─═ц╝╥╡─├▄┬ыгм╟ы╜ў╔ў╩╣╙├бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
HELP
    );
    return 1;
}
