inherit ROOM;
void create()
{
        set("short", "С�ֿ�");
        set("long", @LONG
���Ҳ����̫ƽ�������ֵĵط��������Ŀ����Ǵ�������ȥ�����׵ĺ�ͬ��
��Ϊ��ͬ����Զ������������¥��¥����ǧ�˰��ĵ�Ѫū���С������ͨ������
������أ���������ɢɢ��Щס�ң������������ׯ��
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"sroad4",
		"east" : __DIR__"house3",
		"southeast": __DIR__"eroad1",
		"north": __DIR__"mroad45",
		"south": __DIR__"mroad6",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("coor/x",-20);
      set("coor/y",-50);
      set("coor/z",0);
	set("map","taiping");
	setup();
	
}
