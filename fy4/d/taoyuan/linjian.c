#include <ansi.h>
inherit __DIR__"no_killing_place";
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
ɽ��ï�ܣ�����µ�����ϸ��ǡ��û�㣬��������������������Ż�����
�㣬͸���ּ䣬��Լ�ɼ�����ũ�ҵĴ��̣�ԶԶ�ĺ�������ʮ��ֻ������ּ���Ծ
��Ϸ������һƬ�˼��ɾ���
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"road2",
        "east": __DIR__"milin",
        "south" : __DIR__"linjian1",
    ]));

	set("no_magic", 1);
   	set("outdoors","taoyuan");
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

/*
void init(){
	int i, dayTime;
	mixed *local;
	i = NATURE_D->get_season();
	local = NATURE_D->get_current_time();
	dayTime = local[5];
	if((i = 1 || i = 4) && (dayTime > 330 && dayTime < 370) && NATURE_D->get_weather() == "��") {
		remove_call_out("fog");
		call_out("fog", random(40), this_player());
	}
}
*/


void init_scenery()
{
        if (NATURE_D->get_weather() != "��") return;
        remove_call_out("fog");
        call_out("fog",1);
}

void fog(object me){
	object *inv, *players;
	int i, num = 1+random(10);
	inv = all_inventory();
    	players = filter_array(inv, (: interactive($1) :));
	message("vision", MAG"���ɫ�ĳ����������ּ��أ����������ҫ����˸�����˵���ɫ��\n"NOR, players);
	for(i=0; i<sizeof(players); i++) {
		if (!players[i]->query("����B/��Դ_����")) {
			players[i]->set("����B/��Դ_����",num);
			log_file("riddle/FATE_LOG",
			sprintf("%s(%s) �õ�����B/��Դ_���� "+num+"�� %s \n",
				players[i]->name(1), geteuid(players[i]), ctime(time()) ));
		}
	}   
}


