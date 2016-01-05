// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <room.h>
inherit DOOR_ROOM;
string look_stone();

void create()
{
	set("short", "ˮ����");
    set("long", @LONG
����С��������ʯ֮�󣬲�Ϊ������֪�����﹩�ŵ���һ��������������
����ƺ������С���д�ɨ��һ����Ⱦ����̨��������������ż����𾭣���ƿ
�й��������µ���֦���������Űڷŵþ�Ȼ���򣬿ɼ�ˮ���ֵ�������ϲ����
�徻��
LONG
        );
	set("objects", ([
		__DIR__"npc/nun":1,
		__DIR__"obj/statue" : 1,
		__DIR__"obj/desk" : 1,
		__DIR__"obj/vase" : 1,
//		__DIR__"obj/putun" : 1,
		__DIR__"obj/putun2" : 1,
		__DIR__"obj/vase" : 1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"southdown" : __DIR__"peak12",
	]) );

	set("coor/x",10);
	set("coor/y",60);
	set("coor/z",50);
	setup();
    create_door("southdown","rock","��ʯ","northup",DOOR_CLOSED);
}



void reset()
{
	object river,stone,*inv;
	
	::reset();

	river = present("��ƿ", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/willow");
		if(stone)
			stone->move(river);
	}

	river = present("��", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/nbook");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/nbook1");
		if(stone)
			stone->move(river);
	}

	river = present("����", this_object());
	if (!river)
		return;
	set("long", @LONG
����С��������ʯ֮�󣬲�Ϊ������֪�����﹩�ŵ���һ��������������
����ƺ������С���д�ɨ��һ����Ⱦ����̨��������������ż����𾭣���ƿ
�й��������µ���֦���������Űڷŵþ�Ȼ���򣬿ɼ�ˮ���ֵ�������ϲ����
�徻��
LONG
        );
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/nbook2");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/nbook3");
		if(stone)
			stone->move(river);
	}


	return;
}


void init() {
	add_action("do_get","get");
}



int do_get(string arg) {
	
	string arg1,arg2;
	int num,gao;
	object ye;
	
	if (!ye=present("liaohen",this_object())) return 0;
	if (!arg)
		return 0;
	
	if (sscanf(arg,"%s from %s",arg1,arg2)==2)
	{
		if (arg2 == "vase" || arg2 == "��ƿ" || arg2 == "ƿ" || arg2 == "����ƿ")
			gao=2;
	
		if (arg1 == "willow" && gao == 2) gao=1;
		if (arg1 == "all" && gao == 2) gao=1;
		if (sscanf(arg1,"%s %d",arg2,num)==2)
			if (arg2=="willow" && gao == 2) gao=1;
		
		if (gao != 1)
		{
			if (arg2 == "��" || arg2 == "̨" || arg2 == "��̨" || arg2 == "desk" || arg2 == "table" || arg2 == "����" || arg2 == "putuan")
			{
				if (arg1 == "buddhism book" || arg1 == "all" || arg1 == "book")
					gao=3;
				if (sscanf(arg1,"%s %d",arg2,num)==2)
					if (arg2=="buddhism book") gao=3;
			}
		}
	}
	
	if (gao == 1) {
		message_vision("$Nҡҡͷ��΢Ц������λʩ����Ī������������\n",ye);
		return 1;
	}
	
	if (gao == 3) {
		if (this_player()->query("bellicosity"))
		{
		message_vision("$N΢Ц����ʩ�����������ƣ����뽫�����ֳ�������ȥ��\n",ye);
		}
		else
		{
		message_vision("$Nҡҡͷ��΢Ц������λʩ�������ǽ���������Ե֮�˰ɡ�\n",ye);
		return 1;
		}
	}
	
	return 0;
	
	
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


