inherit ROOM;

void create()
{
	set("short", "��ʯС��");

	set("long", @LONG
������Ǽ������ˣ�������������С�򣬽ֵ�����խ��Щ�������е㶸б����
�Է��ݵĹ���Ҳ��ƽ�������ֺܾ���ֻ�������ҵĴ������ȼ�Ű����ĵƻ���
���Ǽ�Ǯׯ�������������������۵�С·��С�ֱ���һ����ֵ�����Ů�������˸�
���·���С̯���ߴ��ؿ����㡣
LONG);
	set("type","street");
	set("outdoors", "fugui");
	set("exits",([
		"east":__DIR__"shilu1",
		"west":__DIR__"qianzhuang",
		"south":__DIR__"qinshilu",
		"north":__DIR__"xiaojie3",
	]) );
        set("objects", ([
        	__DIR__"npc/clothlady" : 1,
                        ]) );
	set("coor/x",20);
	set("coor/y",80);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
