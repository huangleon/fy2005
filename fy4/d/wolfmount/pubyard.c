#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "��ջ��Ժ");

    set("long", @LONG
������̫ƽ��ջ�ĺ�Ժ����˵��Ժ�ӣ�������û�а�������ǽ��һ��Ʈ����
����ɽϪ��һ����������ţ���һ��������С·��������Զ������ɽɽ�ۣ�������
������һ�ж������ͬ�λð�������翡�
LONG);

    set("type","street");
    set("exits",([
	"north":__DIR__"safepub",
	"southeast":__DIR__"fogpath2",
      ]) );
    set("outdoors", "wolfmount");
    set("objects",([
	__DIR__"npc/bigfoot":1,
      ]) ); 
    set("coor/x",0);
    set("coor/y",-10);
    set("coor/z",0);
    set("item_desc", ([
	"ɽϪ": "һ���������۵�ɽϪ��Ϫˮ�峺�����ƺ������Σ���������ȥ��\n",
	"brook": "һ���������۵�ɽϪ��Ϫˮ�峺�����ƺ������Σ���������ȥ��\n",
      ]) );

    setup();
}

void init()
{		
    add_action("do_swim","swim");
}

int do_swim()
{
    object me;
    object room;
    me = this_player();
    if( me->query_skill("dodge") > 40 )
    {
	message_vision(HIY"$Nһ����������ɽϪ�С�����\n"NOR,me);
	tell_object(me, "������Ϫˮ��ʹ�㲻�ɵش��˸���ս��\n");
	room = find_object(__DIR__"river");
	if(!objectp(room)) room = load_object(__DIR__"river");
	me->move(room);
	me->start_busy(1);

	return 1;
    }
    else
    {
    tell_object(me, HIY"���������������Ա����Ϫˮ������æ���˻���������\n����Ҫ���٣�������Ч����֮����\n"NOR);
	return 1;
    }

}
