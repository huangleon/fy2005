inherit ROOM;

void create()
{
	set("short", "��ʯС��");

	set("long", @LONG
��������������С�򣬽ֵ�����խ��Щ�������е㶸б�����Է��ݵĹ���Ҳ��
ƽ�������ֺܾ���ֻ�������ҵĴ������ȼ�Ű����ĵƻ𡣶����Ǵ˵ض���һ��
�ľƵ꣬���ֺŵġ���Ԫ�ݡ�����������һ���ӻ��̡�
LONG);
	set("type","street");
	set("outdoors", "fugui");

		set("objects", ([
        __DIR__"npc/amine" : 1,
                        ]) );

	set("exits",([
		"east":__DIR__"kuiyuanguan",
		"west":__DIR__"zuohuopu",
		"south":__DIR__"xiaojie3",
		"north":__DIR__"xiaojie1",
	]) );
	set("coor/x",20);
	set("coor/y",100);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
