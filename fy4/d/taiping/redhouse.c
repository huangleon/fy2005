inherit ROOM;
void create()
{
        set("short", "���ĸ�");
        set("long", @LONG
ʮ��һ�������Σ�Ӯ����¥�������������ˣ�����Ҫ���������ഺ����ȡ�Ƹ�
�ĵط�������ԺҲ�ã�������Ҳ�գ�����������¥һ�������ģ��ȵģ��������εģ�
����Ц����𱣬����֬�۵Ľ�����Լ��������ӵĴ�ү�ǡ�¥�µĴ�������Ż��ƣ�
¥��ݺ��Ц�������������硣
LONG
        );
        set("exits", ([ 
		"east": __DIR__"yard",
		"up":	__DIR__"redhouse0",
	]));
        set("item_desc", ([
	
	 ]));
        set("objects", ([
        	__DIR__"npc/piaoke": 1,
        ]));
	set("coor/x",-80);
	set("coor/y",-50);
	set("coor/z",0);
	set("map","taiping");
	set("map","taiping");
	setup();
}
