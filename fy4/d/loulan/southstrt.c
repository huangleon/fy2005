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
		"north" : __DIR__"southstrt3",
		"east" : __DIR__"prison2",
		"south" : __DIR__"southstrt2",
		"west" : __DIR__"weaponroom",
	]));
        set("objects", ([
               __DIR__"npc/guard3" : 1,
	]) );
        set("indoors", "loulan");

	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
    	object ob;
    	object *inv;
    	int i , j, k;
    	
    	j=0;
    	k=0;
    	if ( !userp(me) || dir=="south" || dir=="north")
    		return 1;
    	
    	inv=all_inventory(this_object());
    	for (i=0;i<sizeof(inv);i++)	{
    		if (inv[i]->query("id")=="li yiqi") j=1;
    	}		
    	if (j==0) return 1;

    	inv=all_inventory(me);
    	for(i=0; i<sizeof(inv); i++)		{
		if(inv[i]->query("item_owner")=="������" && (int)inv[i]->query("equipped"))
			k = 1;
	}
	if (k==0) return notify_fail("������������ס���ȥ·��\n");
	return 1;
}
