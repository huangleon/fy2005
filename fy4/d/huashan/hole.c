// annie. 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��ɽ����");
        set("long", @LONG
ת�˼����䣬�붴�����ǰ���һƬ�����ֲ�����ָ��������Ư����Щ
���������㣬����һƬ�ž���ȴ�ƺ������ſ�������ɱ�����㼹���е����
������ͷ�������˵ε��亹���ڰ���ƺ�����Ӱ���ƺ���û�У�̫���ˣ�
LONG
        );
        set("exits", ([ 
		  "southdown" : __DIR__"shanlu1",
	]));
	set("objects", ([
		__DIR__"npc/kumei2": 1,
	]));   

	set("no_fly",1);

	set("coor/x",-52);
	set("coor/y",-60);
	set("coor/z",40);
	setup();
}

void light_notify(object obj, int i)
{
	object inv, me, room;
	int j;
	me = this_player();
	inv = present("shadow",environment(me));
	if (inv)
	{
		message_vision(CYN"$N���һ�����ȵ������ʲô��\n$N����һ���Ʒ磬$n��ʱ������ȥ��\n"NOR,inv,obj);
		return;
	}
	message_vision(obj->name() + "�����Ĺ������˰�����\n" , me);
	if ( REWARD_D->riddle_check(me,"��������") == 4)
	{
		tell_object(me,"������ԼԼ�Ŀ������ϱ����÷����������˼����֣�\n\n����ȥ��ӥ�϶�����"HIG"����"NOR"��\n\n");
		REWARD_D->riddle_set(me,"��������",5);
	}

   return;
}

