//Sinny@fengyun 2003 
//All Rights Reserved ^_^
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "��");
    set("long", @LONG
һ��������������������ĳ����ƾ�Ȼ���Ѿ�Ϩ��ֻ�о�ͷ��ʣ��һյ
�����������ĵĹ�â��һ����Ӱ�����ŵ��µ�ʯ�ڣ�״����˼���������ڸ���ʲ
ô���ܡ�
LONG
    );
    set("exits", 
      ([ 
	"east" : __DIR__"changlang2",
      ]));
    set("objects", 
      ([ 
	__DIR__"npc/jianchi" : 1,
      ]));
    set("item_desc", ([
		"lamp": "һյҡҷ�����ĳ����ƣ���̨�ƺ���Щ�ɶ�������ΪŲ����move���ļ���\n",
		"������": "һյҡҷ�����ĳ����ƣ���̨�ƺ���Щ�ɶ�������ΪŲ����move���ļ���\n",
      ]) );

    set("indoors", "baiyun");
    set("coor/x",-20);
    set("coor/y",-260);
    set("coor/z",30);
    set("no_fly",1);
    setup();
}

void init()
{
    add_action("do_move", "move");
}


int do_move(string arg)
{
    object me;
    me = this_player();
    
    if(arg != "������" && arg != "lamp")
		return notify_fail("��Ҫ��ʲô��\n");
    
    if (REWARD_D->check_m_success(me,"��ͼһ��"))
		return notify_fail("Ҷ�³�����֮���Ѷ���û��Ҫ����ȥ�ˡ�\n");
	    
    if (me->is_fighting() || me->is_busy())
		return notify_fail("��������æ��\n");
		
    if (present("jian chi",this_object()))
    {
		present("jian chi",this_object())->ccommand("say ��������Ҫ���������������ԡ���");
		return 1;
    }
    message_vision(HIB"$N����Ť����̨�����µ�ʯ��ͻȻ������$Nֱֱ׹����ȥ��\n"NOR,me);
    me->move(load_object(__DIR__"mysticroom"));
    me->perform_busy(1);
    message(HIR"vision",me->name()+"����������"NOR,environment(me),me);
    return 1;
}



/*

	       (\~~~/)            
	       ( ����)        

	       (_____)~��      

��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
