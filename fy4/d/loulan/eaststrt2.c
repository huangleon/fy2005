#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
һ���ƻ�ͨ���ĳ��ȣ��ƺ�ԭ�ȱ��Ƿ����Ľֵ���������һЩ��Ժ��լ������
�����ռ�����¥���ĵ��������󣬱㽫���СС����լ���ݸĽ����Թ����¾�ɫ
������ʹ��������ʮ�����Լ��ڶ��������˺�һ�����˾�ס��
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"eaststrt",
		"north" : __DIR__"baihuagong",
		"east" : __DIR__"eaststrt3",
		"south": __DIR__"bedroom",
	]));
        set("objects", ([
               __DIR__"npc/guard2" : 1,
	]) );
        set("indoors", "loulan");

	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
    	object ob;
    	object *inv;
    	int i;
    	int j;
    	int k;
    	j=0;
    	k=0;
    	if ( !userp(me) || dir=="west" || dir=="east" || dir == "south")
    		return 1;
    	
//	if( userp(me) && !me->query_temp("marks/jade_to_zhu"))
//		return notify_fail(YEL"������������װ���������ӡ�������ϲ�����������İ�����˳�����������\n"NOR);
		
    	inv=all_inventory(this_object());
    	for (i=0;i<sizeof(inv);i++)	{
    		if (inv[i]->query("id")=="sun chiqi") j=1;
    	}		
    	if (j==0) return 1;

    	inv=all_inventory(me);
    	for(i=0; i<sizeof(inv); i++)		{
		if(inv[i]->query("item_owner")=="������" && (int)inv[i]->query("equipped"))
			k = 1;
	}
	if (k==0) return notify_fail("�����������ס���ȥ·��\n");

	return 1;
}
