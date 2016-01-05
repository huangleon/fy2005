// Room: /d/wiz/courthouse.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Ψһ��һ���������ܵ�����������һ����������ͷʹ�Ľ�ɫ������һ��
������˵�ͷ�Ͳ�ʹ�ˣ����ͷӦ�ÿ�ʼʹ�˰ɡ�������
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


[37m����ָ�release[32m



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
		tell_object(me,"�������δ�������ô�"+ rest/60 + "���ӡ�\n");
		return 1;
	}
	me->delete("imprison");
	me->move("/d/fy/fyge");
	me->set("startroom","/d/fy/fyge");
	me->save();
	message_vision(CYN"$N�������������������ģ����Ĵ��˵ػص��˷��������\n"NOR,me);
	return 1;
}
	

int do_nothing()
{
	write("������������డ����������\n");
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
		tell_object(this_player(),"�ٶ��������ģ��ú÷�ʡ��ʡ�ɡ�\n");
		return 1;
	}
	this_player()->set_temp("marks/jail_look",time());
	"/cmds/std/look"->main(this_player(),arg);
	return 1;
}
