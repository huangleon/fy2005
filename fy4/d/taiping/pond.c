inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��Χ�����ѿ�ʼ��еĺɻ�����Ҷ������ص����ĸ�ס������������������
����ˮ�棬�����������ֲ������ľ���ټ��ϸ�ǽ���ɣ����ڸ�ǽ֮�⣬��������
�͹��ںڰ��С�������һ�����ţ����ϵ����Ѿ����⡣
LONG
        );
        set("exits", ([ 
		"east": __DIR__"lroad1",
		"south": __DIR__"grass3",
		"north": __DIR__"grass2",
	]));
        set("outdoors", "taiping");
        set("no_fly",1);
	set("item_desc", ([  
		"door": "һ�����ţ����ϵ�ͭ���Ѿ������ˣ�����û���򿪡�\n",
		"����": "һ�����ţ����ϵ�ͭ���Ѿ������ˣ�����û���򿪡�\n",
	]));
	set("coor/x",60);
	set("coor/y",-80);
	set("coor/z",0);
	set("map","taiping");
	setup();
	
}
