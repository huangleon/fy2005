// Silencer@fy4 workgroup

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIW"���Ƶ�"NOR);
	set("long", @LONG
ǰ���Ҫ������������ˣ����¿�ȥ���������ƣ�һ����ΰ�ľ޳�������������
�ò����֣��㲻����Щ�Ļš����ڷ������е����������Ƶ����ѣ���������Ҳ����
������һ�����Ƶ���ء�������[1;31m��[0;32m��һ�����װ�������������������Щ��������
[1;31m�����[0;32m������Կ�һ�����ǵ���;��ǰ;������������׼���ɲ���Ŷ���������
��������·��[1;32m��������[0;32m�Ǹ����ֵģ��и���Ȥ�ģ���������ܼӵ��������
�ۣ�˳���õ��С�̲������ӣ��°���������仯�������������·��ʼ��
[1;32m����������[0;32m�Ǹ��ᳵ��·�Ѿ���������ģ������������ֵ���һ�׶Σ�����һ
�ж��ð�����ң���ʱ��ɲ�Ҫ��Թ���ֿտ�Ŷ��
LONG
	);
	set("exits", ([
  		"newbie" :  AREA_FY"fqkhotel",
  		"veteran" :  AREA_FY"fqkhotel",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",700);
	set("no_magic",1);
	set("no_fight",1);
	setup();
}

int init(){
	object food, drink, drug, intro, me;
	me = this_player();
	if (me->query_temp("first_time_login"))
	{
		food = new("/obj/food_item/newbie_food");
		drink = new("/obj/food_item/newbie_drink");
		drug = new("/obj/medicine/newbie_drug"); 
		intro = new("/obj/item/newbie_letter");
		if (food)	food->move(me);
		if (drink)	drink->move(me);
		if (drug)	drug->move(me);
		if (intro)	intro->move(me);
	}
}


int valid_leave(object me, string dir) {

	if (dir == "newbie") 
		REWARD_D->riddle_set(me,"��������",1);
		
	return ::valid_leave(me, dir);
}