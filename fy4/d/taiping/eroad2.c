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
		"west" : __DIR__"eroad1",
		"southeast" : __DIR__"gate",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("coor/x",30);
	set("coor/y",-70);
	set("coor/z",0);
	set("map","taiping");
	setup();
	
}
