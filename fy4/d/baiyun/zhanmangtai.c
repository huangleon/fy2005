//Created by justdoit at May 2001 
//All Rights Reserved ^_^

#include <ansi.h>;
inherit ROOM;
void create()
{
    set("short", "ն��̨");
    set("long", @LONG
������Ÿ�ɮ��ϴ�ʦӦ���Ƴ���֮�����������ˣ�������̨���ɴ󾪣��Ե���
��ʵ�˰��Ƶ��ķ�ˮ�������ڣ�һ���˴��������⣬����Ƴ�Σ�ڵ�Ϧ�����Ƴ�����
˼���գ���ʱ�����ڴ��˽��˸ߴ���ɵ�ն��̨��Ρ�����졣��������δ�̨ʱ����
ɫ������ã���ڲ��ԡ�
LONG
    );
    set("exits", 
      ([ 
	"east" : __DIR__"skystreet",
      ]));
    set("item_desc", ([
		"ն��̨": "����һ�����ɵ�Σ̨��ңң��ȥ���߲����ʡ�\n",
      ]) );
    set("objects", 
      ([ 
	//       __DIR__"npc/kugua" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",-20);
    set("coor/y",-130);
    set("coor/z",30);
    setup();
}

void init()
{
    add_action("do_climb", "climb");
}


int do_climb(string arg)
{
    object me;
    me = this_player();
    if(arg != "ն��̨" && arg != "up")
		return notify_fail("��Ҫ��ʲô��\n");
    if (me->is_fighting() || me->is_busy())
		return notify_fail("��������æ��\n");
    if (me->query_skill("move",1) < 150)
		return notify_fail("���Ṧ���У�����ǿ����\n");
    message_vision("$Nץסն��̨��͹��ʯ��������ȥ��\n",me);
    
    if (random(2) || !REWARD_D->check_m_success(me,"��ͼһ��"))
    {
		message_vision(HIR"һ�󺣷紵����$N�ֽŷ�����̨�ϵ�����ȥ��\n"NOR,me);
		me->unconcious();
		return 1;
    }
    me->move(load_object(__DIR__"zmttop"));
    me->perform_busy(1);
    message("vision",me->name()+"��̨������������������\n",environment(me),me);
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
