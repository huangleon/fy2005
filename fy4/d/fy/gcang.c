#include <ansi.h>

inherit ROOM;
void create()
{
    set("short", "�ھֻ���");
    set("long", @LONG
��ʨ�ھ������������죬��δʧ�ڡ������Ļ���������ѻ���ɽ���ھֵĻ��
��������æ���ҵ����ڳ���װ�ػ����Ȼÿ����ƶ�����ͷ�󺹣�������Ϊ����
����æ����������������İ�æ�Ļ�������������װ���������룩��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"southeast" : __DIR__"goldlion",
      ]));
    set("objects", ([
	__DIR__"npc/huoji" : 2,
	__DIR__"npc/bad_huoji" : 1,
      ]) );

    set("coor/x",140);
    set("coor/y",-40);
    set("coor/z",0);
    set("map","fyeast");
    setup();
}

void init()
{
    add_action("do_work", "work");
}

int do_work(string arg)
{
    object ob;
    object me;

    me = this_player();
    message_vision(WHT"$N���ھֵĻ�����ڳ���װ�ػ�����û�ۻ��ȥ����\n"NOR,me);
    tell_object(me,"����������Լ��ľ�����״������������������\n");
    
    me->receive_damage("gin",100);
    me->receive_damage("sen",100);
    me->set_temp("last_damage_from","�ڽ�ʨ�ھָɻ����۹��ȶ�����\n");
    me->set("marks/��ʨ", time());
    return 1;
}

