
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����޲������������һ���С���������ɳĮ�У�ͻȻ������������ĵط���
��ֱ�������񻰡���е�ľҶ�䣬��ʱ��������Ц�����������Ȿ�ǻ��ֵ�Ц����
������п�����Ĵ�ɳĮ�У�һ���챻�������˶������Ц��ȴ��ʲ�ᶼҪ����
�ɲ������ѵ��������еĻþ���ħ���������������ľҶ��ѵ�����������
Щר���ջ�¶�������ȥ���ɵĳ���Ů����
LONG
        );
        set("exits", ([ 
	  		"east" : __DIR__"d_tent",
	  		"north": __DIR__"d_bush",
	  		"west": __DIR__"yangguan1",
	  		"southwest": 	__DIR__"yangguan1d",
		]));
	set("objects", ([
		
	]));
	set("item_desc",([
		
	]));
        set("outdoors", "zangbei");
        set("coor/x",-70);
	set("coor/y",310);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}
