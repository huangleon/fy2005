inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
���ϵ�С·ͨ�����ׯ��ׯ�����������ǰ�ᵽ̫ƽ���������������һ
��ׯ԰��û����֪�������������Ҳû����֪�������������ʲô��������ʹ����
��߳����Ƶ�����ү�����������Ҳ�����Ŵ�Ĵָ˵�������򵥡���
LONG
        );
        set("exits", ([ 
		"northwest" : __DIR__"mroad5",
		"east" : __DIR__"eroad2",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("coor/x",20);
	set("coor/y",-70);
	set("coor/z",0);
	set("map","taiping");
	setup();
	
}
