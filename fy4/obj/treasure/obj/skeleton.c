
inherit ITEM;

void create()
{
	set_name("һ�߿�Ǭ�ĺ���", ({ "skeleton" , "����"}) );
	set_weight(400000);
	set_max_encumbrance(500000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�߿�Ǭ�ĺ��ǡ�\n");
		set("value", 1);
	}
}

int is_container() { return 1; }


int init_spawn()
{
	object too, room, sand;
	string room_name;
	
	too = new(__DIR__"budda-tooth");
    too->move(this_object());
	
	room_name = AREA_QUICKSAND+"desert"+ (string)random(10);
	
	room = find_object(room_name);
	if (!room)
		room = load_object(room_name);
	if (!room)
		return 0;
	move (room);
	sand = present("sand", room);
	if (sand)	move(sand);
		else destruct();
/*	CHANNEL_D->do_sys_channel(
                   "sys",sprintf("�����ӱ��ֲ���%s�ˣ���ҿ�����������\n",
                room_name));*/
	return 1;
}

