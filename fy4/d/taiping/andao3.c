#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�ص��ľ�ͷ��һ��ʯ�š����Ե�ǽ���ϸ�����һյ�����ơ����������Ͱ�����
���ϵƴ�ſ���ά�������ա��ƹ�����������ʯ�š���ʯʯ�����������ֵĻ��ƣ�
��Щ����������¥���������Ǽ�ħ���Ż��Ͽ��ŵľ���Щ���ơ�����ɫ�Ļ��ƣ���
���У���ҫ�������ĺ�â������������ģ�ȴ�ƺ���ʲô���������⡣
LONG
        );
        set("exits", ([ 
		"westup":  __DIR__"andao2",
//		"south":  __DIR__"stoneroom",
	]));
        set("item_desc", ([
		"����":	"��ϸ���ϣ�ʯ����д������������֣�--�����⡱��\n",
		"ʯ��":	"��ϸ���ϣ�ʯ����д������������֣�--�����⡱��\n",
		"door":	"��ϸ���ϣ�ʯ����д������������֣�--�����⡱��\n",
		"����":	"�ص��Ķ��ھ�Ȼ�м��ŷ��������ڵķ����к�â��˸��һ��һ�еľ��Ƿ�����ǹ�⡣
ǧ��֧��ǹһ�����£��ص��е����߱ܲ�����ɴ�⬡��������ź�ÿ��ٺ��ˣ���
�ܶ��������ء�\n",
		"roof":	"�ص��Ķ��ھ�Ȼ�м��ŷ��������ڵķ����к�â��˸��һ��һ�еľ��Ƿ�����ǹ�⡣
ǧ��֧��ǹһ�����£��ص��е����߱ܲ�����ɴ�⬡��������ź�ÿ��ٺ��ˣ���
�ܶ��������ء�\n",
	 ]));
	set("coor/x",110);
	set("coor/y",-50);
	set("coor/z",-20);
	set("map","taiping");
	setup();
}

void init()
{
       	add_action("do_push", "push");
       	add_action("do_open","open");
}

int	do_open(string arg){
	if (arg == "door" || arg=="ʯ��" || arg=="��"){
		tell_object(this_player(),"ʯ�Ž������ţ�Ҫ������һ�²��С�\n");
		return 1;
	}
}

void close_passage()
{
        object room;
        message("vision", "ʯ��������Ϣ����ת�˻�������ס�˰�����\n", this_object() );
        set("door_opening",0);
        delete("exits/south");
}

int do_push(string arg)
{
        object obj, room, me;
        me=this_player();
        if(!arg || (arg != "ʯ��" && arg != "��" && arg !="door")) {
                return 0;
        }
	if (query("exits/south"))
		return notify_fail("ʯ���Ѿ����ˡ�\n");
	if (me->query_str()<=60)
		return notify_fail("��һ����ȥ��ʯ����˿������\n");
	if (query("door_opening"))
		return notify_fail("ʯ���Ѿ����ƶ��ˡ�\n");
	
	message_vision(YEL"$N˫����סʯ�ţ��Ϳ�����һ��������һ�����������ϣ���\n"NOR,me);
	message_vision(YEL"�����������أ�ʯ�ſ�ʼ�����ƶ���������\n"NOR,me);
	set("door_opening",5);
	call_out("arrow_trap", 6);
        return 1;
}


void open_passage() {
	message("vision","֨֨�¸�һ���춯��ʯ�����ڴ��ˡ�\n",this_object());
	set("exits/south",__DIR__"stoneroom");	
	call_out("close_passage", 20);
}

void arrow_trap() {
	object *inv;
	int i;
	message("vision",WHT"\n��Ȼ��������л���֮�������������Ͼ�Ȼ�������ʮ֧��ǹ��\n\n"NOR,this_object());
	inv=all_inventory(this_object());
	for (i=0;i<sizeof(inv);i++) {
		if (!inv[i]->is_character()|| inv[i]->is_corpse()) continue;
		message_vision(WHT"$N��ܲ���������ǹ���˸�͸����������\n"NOR,inv[i]);
		inv[i]->set_temp("last_damage_from","�л�����ǹ���������\n");
		inv[i]->receive_wound("kee",12000);
		COMBAT_D->report_status(inv[i]);
	}
	call_out("open_passage", 4);
}

void reset()
{
        ::reset();
        delete("exits/south");
	set("door_opening",0);
}


