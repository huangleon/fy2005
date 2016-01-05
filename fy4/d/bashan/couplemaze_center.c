#include <ansi.h>

inherit __DIR__"card.c";
inherit ROOM;


#define N -6
#define E 1
#define W -1
#define S 6

void create()
{
	set("short", "�����İ�ɽ��ҩ��");
        set("long", @LONG
һ�����ݣ�ǽ��֧�ŵ�һ�Ŵ�����ɫ����ȥ�����Ŀ�⣬������ȥ��ԭ����
ϵ��һ�����֮�ϵĴ��«�������������Ƶ����¡�ֻ���Ǻ�«��Ѱ���߷������
���ϵĺ�«������ͬ��ͨ��������ˢ�ˣ�ԶԶ��ȥٲȻһ����ɰ�·��ٿ�������
ᦣ�ȴ����Ϊƽ�������Ĵֲ����Ҳ�����������ۡ�����˸����֣�������������
��Ϊ�������ּ��ʲݣ���ī���ӣ�ȫ���·����ԡ�
LONG
        );
	set("room_num",-1);
	set("exits",([
  		" " : __DIR__"jadegate",
	]) );
	// nothing
	set("no_fly",1);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_cardhp","hp");
	add_action("do_cardstart","start");
	add_action("do_use","use");
	add_action("do_skip","skip");
}

int kickout_ppl()
{
	string msg;
	object room,nothing,*inv,o1,o2;
	mapping c;
	mapping buff_list,buff;
	string *lists;
	int i,j;
	msg = __DIR__"couplemaze_";
	for (i=1; i<25; i++)
	{
		room = nothing;
		if (!room = find_object(msg+i))
			room = load_object(msg+i);
		if (!room)
			continue;
		inv = all_inventory(room);
		for (j=0;j<sizeof(inv) ; j++)
		{
			if (userp(inv[j]) && !o1)
				o1 = inv[j];
			else if (userp(inv[j]) && !o2)
				o2 = inv[j];
			else if (userp(inv[j]))
				tell_object(inv[j],"����#12101��\n");	// ÿ�����������ֻ��������player
		}
	}
	if (!room = find_object(__DIR__"restroom"))
		room = load_object(__DIR__"restroom");
	if (o1)
		o1->move(room);
	if (o2)
		o2->move(room);
	return 1;
}

int close_all_path()
{
	string msg;
	object room,nothing;
	mapping c;
	mapping buff_list,buff;
	string *lists;
	int i,j;
	msg = __DIR__"couplemaze_";
	for (i=1; i<25; i++)
	{
		room = nothing;
		if (!room = find_object(msg+i))
			room = load_object(msg+i);
		room->delete("exits");
		c = room->query("exist_exits");
		if( !mapp(c) || !sizeof(c) )
			continue;
		lists = keys(c);
		for(j=0; j<sizeof(lists); j++)
			room->set("exits/"+lists[j],room->query("exist_exits/"+lists[j]));
	}
	return 1;
}

object getroom(int idx)
{
	object room;
	string rn,msg;
	msg = __DIR__"couplemaze_";
	rn = msg + idx;
	if (!room = find_object(rn))
		room = load_object(rn);
	tell_object(room,CYN"һ��ңԶ�ĺ������͵ʹ�����һ��ʯ��������ǰ�����ƿ�������\n"NOR);
	return room;
}

int open_path(int n)
{
	object room,nothing;
	int i;

	switch (n)
	{
	case 1:
		room = getroom(13);
		room->set("exits/south", __DIR__"couplemaze_"+(room->query("room_num")+6));
		room = getroom(18);
		room->set("exits/south", __DIR__"couplemaze_"+(room->query("room_num")+6));
		room = getroom(24);
		room->set("exits/north", __DIR__"couplemaze_"+(room->query("room_num")-6));
		break;
	case 2:
		room = getroom(14);
		room->set("exits/west", __DIR__"couplemaze_"+(room->query("room_num")-1));
		room = getroom(18);
		room->set("exits/north", __DIR__"couplemaze_"+(room->query("room_num")-6));
		room = getroom(12);
		room->set("exits/south", __DIR__"couplemaze_"+(room->query("room_num")+6));
		break;
	case 3:
		room = getroom(15);
		room->set("exits/west", __DIR__"couplemaze_"+(room->query("room_num")-1));
		room = getroom(12);
		room->set("exits/north", __DIR__"couplemaze_"+(room->query("room_num")-6));
		room = getroom(6);
		room->set("exits/south", __DIR__"couplemaze_"+(room->query("room_num")+6));
		break;
	case 4:
		room = getroom(21);
		room->set("exits/north", __DIR__"couplemaze_"+(room->query("room_num")+N));
		room = getroom(6);
		room->set("exits/west", __DIR__"couplemaze_"+(room->query("room_num")+W));
		room = getroom(5);
		room->set("exits/east", __DIR__"couplemaze_"+(room->query("room_num")+E));
		break;
	case 5:
		room = getroom(16);
		room->set("exits/south", __DIR__"couplemaze_"+(room->query("room_num")+S));
		room = getroom(5);
		room->set("exits/west", __DIR__"couplemaze_"+(room->query("room_num")+W));
		room = getroom(4);
		room->set("exits/east", __DIR__"couplemaze_"+(room->query("room_num")+E));
		break;
	case 6:
		room = getroom(3);
		room->set("exits/east", __DIR__"couplemaze_"+(room->query("room_num")+E));
		room = getroom(14);
		room->set("exits/south", __DIR__"couplemaze_"+(room->query("room_num")+S));
		room = getroom(20);
		room->set("exits/north", __DIR__"couplemaze_"+(room->query("room_num")+N));
		break;
	case 7:
		room = getroom(8);
		room->set("exits/south", __DIR__"couplemaze_"+(room->query("room_num")+S));
		room = getroom(4);
		room->set("exits/south", __DIR__"couplemaze_"+(room->query("room_num")+S));
		room = getroom(10);
		room->set("exits/north", __DIR__"couplemaze_"+(room->query("room_num")+N));
		break;
	case 8:
		room = getroom(9);
		room->set("exits/east", __DIR__"couplemaze_"+(room->query("room_num")+E));
		room = getroom(8);
		room->set("exits/west", __DIR__"couplemaze_"+(room->query("room_num")+W));
		room = getroom(7);
		room->set("exits/east", __DIR__"couplemaze_"+(room->query("room_num")+E));
		break;
	case 9:
		room = getroom(8);
		room->set("exits/east", __DIR__"couplemaze_"+(room->query("room_num")+E));
		room = getroom(1);
		room->set("exits/south", __DIR__"couplemaze_"+(room->query("room_num")+S));
		room = getroom(7);
		room->set("exits/north", __DIR__"couplemaze_"+(room->query("room_num")+N));
		break;
	case 10:
		room = getroom(3);
		room->set("exits/south", __DIR__"couplemaze_"+(room->query("room_num")+S));
		room = getroom(2);
		room->set("exits/west", __DIR__"couplemaze_"+(room->query("room_num")+W));
		room = getroom(1);
		room->set("exits/east", __DIR__"couplemaze_"+(room->query("room_num")+E));
		break;
	case 11:
		room = getroom(3);
		room->set("exits/west", __DIR__"couplemaze_"+(room->query("room_num")+W));
		room = getroom(3);
		room->set("exits/north", __DIR__"maze2/entry");
		break;
	case 12:
		room = getroom(17);
		room->set("exits/south", __DIR__"couplemaze_"+(room->query("room_num")+S));
		room = getroom(16);
		room->set("exits/west", __DIR__"couplemaze_"+(room->query("room_num")+W));
		room = getroom(15);
		room->set("exits/east", __DIR__"couplemaze_"+(room->query("room_num")+E));
		break;
	case 13:
		room = getroom(7);
		room->set("exits/south", __DIR__"couplemaze_"+(room->query("room_num")+S));
		room = getroom(11);
		room->set("exits/south", __DIR__"couplemaze_"+(room->query("room_num")+S));
		room = getroom(17);
		room->set("exits/north", __DIR__"couplemaze_"+(room->query("room_num")+N));
		break;
	case 14:
		room = getroom(18);
		room->set("exits/west", __DIR__"couplemaze_"+(room->query("room_num")+W));
		room = getroom(10);
		room->set("exits/south", __DIR__"couplemaze_"+(room->query("room_num")+S));
		room = getroom(16);
		room->set("exits/north", __DIR__"couplemaze_"+(room->query("room_num")+N));
		break;
	case 15:
		room = getroom(17);
		room->set("exits/west", __DIR__"couplemaze_"+(room->query("room_num")+W));
		room = getroom(11);
		room->set("exits/west", __DIR__"couplemaze_"+(room->query("room_num")+W));
		room = getroom(10);
		room->set("exits/east", __DIR__"couplemaze_"+(room->query("room_num")+E));
		break;
	case 16:
		room = getroom(5);
		room->set("exits/south", __DIR__"couplemaze_"+(room->query("room_num")+S));
		room = getroom(9);
		room->set("exits/south", __DIR__"couplemaze_"+(room->query("room_num")+S));
		room = getroom(15);
		room->set("exits/north", __DIR__"couplemaze_"+(room->query("room_num")+N));
		break;
	case 17:
		room = getroom(11);
		room->set("exits/east", __DIR__"couplemaze_"+(room->query("room_num")+E));
		room = getroom(2);
		room->set("exits/south", __DIR__"couplemaze_"+(room->query("room_num")+S));
		room = getroom(8);
		room->set("exits/north", __DIR__"couplemaze_"+(room->query("room_num")+N));
		break;
	}
	return 1;
}



/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/



/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
