//Created by justdoit at May 2001 
//All Rights Reserved ^_^
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "����¥");
    set("long", @LONG
Σ�����գ��������������֮�ߣ�Ҷ�³��Ļ����£���־�г�һ����¹��ԭ����
��¥�ش����Ƶ����֮�����·�һ���������Ƴ���ңָ��ԭ���ݡ�¥�ϱ������һ
����̨�Ϻ������ɵ������汱ӭ�硣
LONG
    );
    set("exits", 
      ([ 
	"north" : __DIR__"yuequedian",
	//       "south" : __DIR__"changlang",
      ]));
    set("item_desc", ([
	"chair": "����һ�ž޴�ĺ������ɵ����Σ��������������������צ������
�������೤������������ƺ����Էֱ�Ť��(twist)��\n",
	"����": "����һ�ž޴�ĺ������ɵ����Σ��������������������צ������
�������೤������������ƺ����Էֱ�Ť��(twist)��\n",
      ]) );
    set("objects", 
      ([ 
	"/obj/specials/ding/ding_by":	1,	
	__DIR__"npc/fakemaster" : 1,
	__DIR__"npc/jiankuang" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-240);
    set("coor/z",30);
    setup();
}


void init()
{
    add_action("do_twist", "twist");
}


int do_twist(string arg)
{
    object me;
    me = this_player();
    if(arg != "left" && arg != "right")
	return notify_fail("��ҪŤ���ıߵ���ͷ����right or left��\n");
    
    if (me->is_fighting() || me->is_busy())
		return notify_fail("��������æ��\n");
    
    if (REWARD_D->riddle_check(me,"��ͼһ��") !=10 )
    {
		if (present("jian kuang",this_object()) && !userp(present("jian kuang",this_object())))
		{
		    present("jian kuang",this_object())->ccommand("bite");
		    present("jian kuang",this_object())->ccommand("say ��ʦ�ڴˣ��ݵú�����");
		    return 1;
		}
		if (present("Master ye",this_object()) && !userp(present("Master ye",this_object())))
		{
		    present("Master ye",this_object())->ccommand("heng");
		    present("Master ye",this_object())->ccommand("say �Ϸ���ǰҲ�ҷ�����");
		    return 1;
		}
    }
    
    if (arg == "left")
    {
		message_vision(YEL"$NŤ����һ�����ϵ���ͷ��
��֨֨һ�����죬����������Ų�˿�ȥ�������������ɭɭ�Ķ��ڡ�
$N�ڲ�ס����֮�ģ�С��������߽����С�\n"NOR,me);
		me->move(load_object(__DIR__"changlang"));
		me->perform_busy(1);
		message("vision",me->name()+"���˹�����",environment(me),me);
		return 1;
    }
    
    message_vision(YEL"$NŤ����һ�����ϵ���ͷ��
��֨һ�����ذ�ͻȻ������$N�ҽ�һ��������ȥ��\n"NOR,me);
    me->move(load_object(__DIR__"pailangya"));
    me->perform_busy(1);
    message("vision",me->name()+"����������",environment(me),me);

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
