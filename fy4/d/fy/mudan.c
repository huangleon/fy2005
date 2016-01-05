#include <ansi.h>
#include <room.h>
inherit ROOM;

string *marryfood_names=({
  YEL"���ֻ���"NOR,HIW"���͹���"NOR,HIG"���ݴ���"NOR,
  HIC"��Ƭ����"NOR,HIW"������˺��"NOR,HIW"��֭����"NOR,YEL"���ƴ�Ϻ"NOR,
  WHT"ˮ��Ϻ��"NOR,HIY"�ƽ���зǯ"NOR,YEL"���ö���"NOR,
  HIG"������Ϻ��"NOR,RED"�����Ƭ"NOR,HIW"��ϲ����"NOR,HIY"������Ѽ"NOR,
  YEL"�л���"NOR,HIR"������˿"NOR,HIW"��ն��"NOR,WHT"��ˮѼ"NOR,YEL"���������"NOR,
  RED"��������"NOR,HIR"���޷�Ƭ"NOR,WHT"���������"NOR,YEL"�����Ƥ��"NOR,
  YEL"����˫ϲ������"NOR,GRN"������˫����"NOR
});
//������Ե��  �Ҹ�������  ����ú�  ����ͬ��  �׷���ü 

string *food_names=({
  MAG"��������"NOR,YEL"Խ���𹳳�"NOR,YEL"��ͼ���ʴ�����"NOR,
  HIC"��Ƭ����"NOR,HIW"������˺��"NOR,HIW"��֭����"NOR,
  HIY"�ƽ���зǯ"NOR,HIY"������"NOR,RED"�������"NOR,
  HIG"���Ӻ�����"NOR,RED"�����Ƭ"NOR,HIW"��ϲ����"NOR,HIY"������Ѽ"NOR,HIR"������"NOR,
  YEL"�л���"NOR,HIR"������˿"NOR,HIW"��ն��"NOR,WHT"��ˮѼ"NOR,YEL"���������"NOR,
  RED"��������"NOR,HIR"���޷�Ƭ"NOR,HIR BLK"����������"NOR,YEL"��ʽ��Ѽ"NOR
});

string *wine_names=({
  WHT"�׾�"NOR, GRN"��Ҷ��"NOR, YEL"���˾�"NOR, HIR"Ů����"NOR,
  WHT"ę́��"NOR,RED"�𻨾�"NOR,RED"���껨��"NOR,WHT"����Һ"NOR,
  HIR"�ſ���"NOR,WHT"�յ���"NOR,RED"���Ѿ�"NOR,HIW"͸ƿ��"NOR,HIG"�ٲݾ�"NOR,
  HIR"״Ԫ��"NOR,GRN"�滨��"NOR,BLK"�ƹ��"NOR
});

string *water_names=({
  HIG"������"NOR, RED"�ն���"NOR, GRN"®ɽ����"NOR, HIG"��ɽ����"NOR,
  GRN"���ݴ�"NOR,HIG"������"NOR,GRN"������"NOR
});

string *cup_names=({
  MAG"��ɰ��"NOR, WHT"ˮ��յ"NOR, HIW"�´ɱ�"NOR, GRN"��䱭"NOR,
  HIY"������"NOR,MAG"��̴��"NOR,YEL"�̽�"NOR,WHT"������"NOR,HIG"��ͭ��"NOR,
  WHT"��֬����"NOR,HIW"ҹ�Ɑ"NOR,YEL"Ϭ�Ǳ�"NOR,RED"���ٱ�"NOR,HIY"������"NOR
});

varargs protected void create_food(string nmstr, string* idlist)
{
    object obj,table;

    obj = new(__DIR__"obj/food");
    obj->set_name(nmstr, idlist);
    obj->set("long", GRN+"һ����������, �������"+nmstr+"��\n"+NOR);
    table = present("table", this_object());
    obj->move(table);
}

varargs protected void create_water(string nmstr, string* idlist, string cup)
{
    object obj,table;

    obj = new(__DIR__"obj/water");
    obj->set_name(cup, idlist);
    obj->set("long", YEL+"һ�����ȵ�" + nmstr + "��\n" + NOR);
    obj->set("liquid/name", nmstr);
    table = present("teatable", this_object());
    obj->move(table);
}

varargs protected void create_wine(string nmstr, string* idlist, string cup)
{
    object obj,table;

    obj = new(__DIR__"obj/wine");
    obj->set_name(cup, idlist);
    obj->set("long", RED+"һ��������" + nmstr + "��\n" + NOR);
    obj->set("liquid/name", nmstr);
    table = present("bar", this_object());
    obj->move(table);
}

void create()
{
    set("short", HIG"õ������"NOR);
    set("long", @LONG
�����ƹ�һ�����Ƴ����磬ӭ��ǽ�Ϲ���һ������������ͼ��������
�Σ�������֣���������ӯ�ҡ����ڳ����ݻ���������һ�ŵ��ľ����Ƕ
���Բ��������ʮ���������������ֺ�ľ�Σ��������磬�������ԡ�
�������ǧ��¥�����ĵ�������������ƽ����һ�ݲ˵�(menu)��
LONG );
    set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"huanyun3",
      ]));
    set("no_sleep_room",1);
    set("item_desc", ([
	"menu": @TEXT

�����ʽ��ϯ, ��ӭ�ݹˣ�

        order marry:    ���ϲ��        (50���ƽ�)

        order party:    Ӣ�۴���        (100���ƽ�)

        order end:      �������

TEXT
      ]) );

    set("no_fight",1);
    set("no_magic",1);
    set("NONPC",1);      
    set("coor/x",-40);
    set("coor/y",-200);
    set("coor/z",0);
    set("map","fysouth");

    setup();

}

void init()
{
    object me;

    add_action("do_order", "order");
    add_action("do_get", "get");
}
int do_get(string arg)
{
    if (!arg)	return 0;
    if (arg=="all" && query("order_owner")){
	write("�ѵ����������·�����ô���θ�ڣ�\n");
	return 1;
    }
    return 0;
}


int do_order(string arg)
{
    object me, env, table;
    object* oblist;
    string name,msg;
    int idx,size,i;

    me = this_player();
    env = this_object();
    name = query("order_owner");
    if (name && (arg == "end") && (name == me->query("id"))) {
	msg = "ĵ��������������  !!!\n";
	CHANNEL_D->do_sys_channel("info",msg);
	delete("order_owner");
	delete("order_type");
	oblist = all_inventory(env);
	for(idx=0; idx<sizeof(oblist); idx++) {
	    if (!objectp(oblist[idx]))
		continue;
	    if (userp(oblist[idx]))
		continue;
	    destruct(oblist[idx]);
	}
	return 1;
    }
    if (name)
	return notify_fail("�����Ѿ����˰�����.\n");
    if (arg == "marry") {
	if (me->query("deposit") < 500000) return notify_fail("������д���\n"); //100g
	me->add("deposit",-500000);
	tell_object(me,HIG"��Ṳ����ʮ���ƽ�лл�ݹˣ�\n"NOR);
	msg = me->name() + "������ǧ��¥ĵ�������ж�������ˣ�������ϲ����ϲ��\n";

	table = new("/d/fy/obj/table");
	table ->move(environment(me));
	table = new("/d/fy/obj/bar");
	table ->move(environment(me));
	table = new("/d/fy/obj/teatable");
	table ->move(environment(me));

	create_food(CYN"������Ե��"NOR, ({ "meal" }) );
	create_food(YEL"�Ҹ�������"NOR, ({ "noodle" }) );
	create_food(WHT"����ú�"NOR, ({ "meal" }) );
	create_food(HIR"����ͬ��"NOR, ({ "meal" }) );
	create_food(HIW"�׷���ü"NOR, ({ "meal" }) );
	create_food(RED"ϲ��"NOR, ({ "candy" }) );
	create_food(RED"ϲ��"NOR, ({ "candy" }) );
	create_food(RED"ϲ��"NOR, ({ "candy" }) );
	create_food(RED"ϲ��"NOR, ({ "candy" }) );
	create_food(RED"ϲ��"NOR, ({ "candy" }) );

	size = sizeof(marryfood_names);
	for(i=0;i<20;i++)  {
	    create_food(marryfood_names[random(size)],({"food"}));
	}

	size = sizeof(wine_names);
	for(i=0;i<15;i++)  {
	    create_wine(wine_names[random(size)],({"wine"}),cup_names[random(sizeof(cup_names))]);
	}

	size = sizeof(water_names);
	for(i=0;i<5;i++)  {
	    create_water(water_names[random(size)],({"tea"}), cup_names[random(sizeof(cup_names))]);
	}

    } else if (arg == "party") {

	if (me->query("deposit") < 1000000) return notify_fail("������д���\n"); //100g
	me->add("deposit",-1000000);
	tell_object(me,HIG"��Ṳ��һ�����ƽ�лл�ݹˣ�\n"NOR);
	msg = me->name() + "������ǧ��¥ĵ���������·Ӣ�ۺ���!��ҿ����׳԰��ð���\n";

	table = new("/d/fy/obj/table");
	table ->move(environment(me));
	table = new("/d/fy/obj/bar");
	table ->move(environment(me));
	table = new("/d/fy/obj/teatable");
	table ->move(environment(me));

	create_food(CYN"�ʶ�����"NOR, ({ "meal" }) );
	create_food(BLK"��ƶ���"NOR, ({ "meal" }) );
	create_food(HIC"��ʮ����������"NOR, ({ "meal" }) );
	create_food(HIW"����ѩ��"NOR, ({ "meal" }) );
	create_food(HIG"������Ϻ��"NOR, ({ "meal" }) );


	size = sizeof(food_names);
	for(i=0;i<30;i++)  {
	    create_food(marryfood_names[random(size)],({"food"}));
	}

	size = sizeof(wine_names);
	for(i=0;i<15;i++)  {
	   create_wine(wine_names[random(size)],({"wine"}),cup_names[random(sizeof(cup_names))]);
	}

	size = sizeof(water_names);
	for(i=0;i<5;i++)  {
	    create_water(water_names[random(size)],({"tea"}), cup_names[random(sizeof(cup_names))]);
	}
    }
    else {
	return notify_fail("��Ҫ��ʲô��ϯ?\n");
    }
    CHANNEL_D->do_sys_channel("info",msg);
    set("order_owner", me->query("id"));
    set("order_type", arg);
    return 1;
}
int valid_leave(object me, string dir)
{
    if (me->query("id") != query("order_owner"))
	return 1;
    return notify_fail(RED + "���� order end ������������뿪��\n" + NOR);
}

