// Room: neishi.c --- by MapMaker
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");

	set("long", @LONG
��������ͷ����ס��С�ݣ������Ű崲�⣬��ª���ƺ���ֻʣ�»���ɾ�����
�ں������е�һ��Сľͷ���ˡ������ϵ���յ�͵ƣ�����������ҡҷ�š�
LONG);

	//{{ --- by MapMaker
	set("exits",([
		"south":__DIR__"yard",
	]) );
	
	set("item_desc", ([
		"����":		"һ������ͨͨ�����ӡ�\n",
		"�崲":		"һ������ͨͨ�İ崲��\n",
		"bed":		"һ������ͨͨ�İ崲��\n",
		"table":	"һ������ͨͨ�����ӡ�\n",
	]));		
	
        set("indoors", "libie");
	set("coor/x",-5);
	set("coor/y",20);
	set("coor/z",0);

	setup();

}

int valid_enter(object me)
{	
	object ob, letter;
	
	if(me->query_temp("libie/���_ȡ��"))
	if(ob = present("old yu", this_object()))
	if(ob->query("��"))
		ob->start_call_out( (: call_other, ob, "give_letter" ,me:), 1);
	return 1;
}
