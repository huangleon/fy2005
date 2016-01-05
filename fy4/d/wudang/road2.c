
inherit ROOM;

void create()
{
	set("short", "��ɽ·");
	set("long", @LONG
��������������·��ȴ��ƽ̹���������߶���ïʢ�����֣��������ʱ������
�������������ķҷ�����һ����ʹ�����ؿ��ʣ�����һ�з��ա���Զ��ǰ������
һ���ʯ��һ��Сͤ�ӡ�
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"gate",
		"southup" : __DIR__"xuanwumen",
		"west" : __DIR__"pine1",
		"east" : __DIR__"pine3",
	]));
	set("outdoors", "wudang");
	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",-40);
	setup();
}


int valid_leave(object obj, string dir){
	object *inv, *npc,room;
	int i, j;
	
	if (dir != "east")
		return ::valid_leave(obj, dir);

	room = find_object(__DIR__"pine3");
	if (!room) room = load_object(__DIR__"pine3");
	
	npc = all_inventory(room);
//npc = filter_array(inv, (: $1->query("id") == "taoist elder" :));
	
	j = 0;
	if (npc)
	for(i=0; i<sizeof(npc); i++) {
		if (npc[i]->is_fighting())
			return notify_fail("�����｣���������㾹Ȼ�޷�������\n");
		if (userp(npc[i]))	j++;		
	}
	
	if (j>=4)
		return notify_fail("�ּ�յ���С���Ѿ�û�����¸�������ˡ�\n");
	
	room->reset();
				
	return ::valid_leave(obj, dir);
}