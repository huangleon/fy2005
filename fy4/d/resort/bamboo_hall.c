
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����������СС�Ĵ����ݣ����м������еļҾ߶����������ɵģ�͸��
�ɶ����˵����㣬������ô������ζ�أ������������ɰ������ݳ����������㣿
ǽ������һ��ī�񣬱����ݺᣬī�����죬����ɭɭ֮�⡣���Ϸ���һ�����٣�һ
�ܶ��һ��������Ů����Ʒ�����塣
LONG
        );
        set("exits", ([ 
		  "south" : __DIR__"front_yard",
		  "north" : __DIR__"back_yard",
		  "west" : __DIR__"teagarden",
		  "east" : __DIR__"restroom",
	]));
        set("objects", ([
                __DIR__"npc/master" : 1,
                __DIR__"npc/master2" : 1,
                __DIR__"npc/girl" : 1,
        ]) );
        set("valid_startroom", 1);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
    
    REWARD_D->riddle_done(me,"��ѩ����",10,1);
    
    if (QUESTS_D->verify_quest(me,"��ѩ����"))
		QUESTS_D->special_reward(me,"��ѩ����");
		
    if( me->query("class") != "legend" && (dir == "east"|| dir== "west")) {
    	if(ob=present("master tieshao", this_object())){
        	return notify_fail("����΢΢������ü��\n\n��������·��"+ob->name()+"��ס�� ��\n");
		} else if(ob=present("master xuerui", this_object())){
			return notify_fail(ob->name()+"��ü΢����\n\n��������·��"+ob->name()+"��ס�� ��\n");
		}
	}
	return 1;
}
