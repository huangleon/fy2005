// Room: /d/wiz/courthouse.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "¼àÓü");
	set("long", @LONG
·çÔÆÀïÎ¨Ò»µÄÒ»¸ö¼àÓü£¬ÄÜµ½ÕâÀïÀ´µÄÈËÒ»¶¨¶¼ÊÇÁîÈËÍ·Í´µÄ½ÇÉ«¡£µ«ÊÇÒ»µ½
ÕâÀï£¬±ğÈËµÄÍ·¾Í²»Í´ÁË£¬ÄãµÄÍ·Ó¦¸Ã¿ªÊ¼Í´ÁË°É¡£¡£¡£¡£
                                           /\ /\
                                          /  \---._
                                         / / `     `\
                                         \ \   `'<@)@)
                                         /`         ~ ~._
                                        /                `()
                                       /    \   (` ,_.:.  /
                                      / ~    `\   (vVvvvvV
                                     /       |`\_ `^^^/
                                 ___/________|_  `---'
                                (_____R_E_X____) _
                                _/~          | `(_)
                              _/~             \
                            _/~               |
                          _/~                 |
                        _/~                   |
                      _/~         ~.          |
                    _/~             \        /\
                 __/~               /`\     `||
               _/~      ~~-._     /~   \     ||
              /~             ~./~'      \    |)
             /                 ~.        \   )|
            /                    :       |   ||
       jgs  |                    :       |   ||
            |                   .'       |   ||
       __.-`                __.'--.      |   |`---.
    .-~  ___.         __.--~`--.))))     |   `---.)))
   `---~~     `-...--.________)))))      \_____)))))


[37m³öÓüÖ¸Áî£ºrelease[32m



LONG
	);
        set("exits", ([ /* sizeof() == 2 */
//  		"west" : __DIR__"jobroom"
	]));

	set("no_fight", 1);
	set("no_magic", 1);
	set("no_spells", 1);
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",20);
	setup();
}

void init()
{
        if(!wizardp(this_player()))
	{
		"/cmds/std/look"->look_room(this_player(),this_object());
		this_player()->set("startroom", __FILE__);
        	add_action("do_nothing", "");
		add_action("do_quit","quit");
		add_action("do_look","look");
		add_action("do_out", "release");
	}
}	

int do_out(){
	object me = this_player();
	int rest;
	
	rest = me->query("imprison/start") + me->query("imprison/duration") - time();
	if ( rest > 0 ) {
		tell_object(me,"ÄãµÄĞÌÆÚÎ´Âú£¬»¹µÃ´ô"+ rest/60 + "·ÖÖÓ¡£\n");
		return 1;
	}
	me->delete("imprison");
	me->move("/d/fy/fyge");
	me->set("startroom","/d/fy/fyge");
	me->save();
	message_vision(CYN"$N½áÊøÁËÂş³¤µÄÌú´°ÉúÑÄ£¬ÂúĞÄ´´ÉËµØ»Øµ½ÁË·çÔÆÊÀ½çÀï¡£\n"NOR,me);
	return 1;
}
	

int do_nothing()
{
	write("¼àÓüµÄÉú»îÕæ¿à°¡£®£®£®£®£¡\n");
	return 1;
}

int do_quit()
{
	"/cmds/usr/quit"->main(this_player(),"");
	return 1;
}

int do_look(string arg)
{
	if (this_player()->query_temp("marks/jail_look")+4 > time()){
		tell_object(this_player(),"ÉÙ¶«ÕÅÎ÷ÍûµÄ£¬ºÃºÃ·´Ê¡·´Ê¡°É¡£\n");
		return 1;
	}
	this_player()->set_temp("marks/jail_look",time());
	"/cmds/std/look"->main(this_player(),arg);
	return 1;
}
