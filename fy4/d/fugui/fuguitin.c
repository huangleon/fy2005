inherit ROOM;

void create()
{
	set("short", "����������");

	set("long", @LONG
���Ǹ���ɽׯ�������������������������Ӻܴ󣬽���Ҳ���ûʣ�����ھ�ϯ
���Է���ʮ�������ӣ���������ֵ��ǣ�ټ��һ�����ӣ�����һ��ټ��Ĵ����⣬
��ʲôҲû���ˣ������Ŵ���ֱ�ȳ�����Ĺ��ӻ����壬�ƺ�������ʲô�ط�����
һ�����ܻ�����һ�����ʣ���⣬���ĸ���û��������ͷ����Ϊ���˵��ǣ�ֻ��
ʱ��ʱ�м�ֻ�����ϴ���������������ɢ����һ�ּ�����Ũ�������Ĺ�ζ.
LONG
	);
	set("type","house");
	set("valid_startroom", 1);
	set("indoors", "fugui");
	set("exits",([
		"east":__DIR__"shibanlu2",
		"west":__DIR__"suishilu2",
		"south":__DIR__"suishilu1",
		"north":__DIR__"shibanlu4",
	]) );
	set("objects",([
		__DIR__"npc/wang" : 1,
       	]) );
        set("item_desc", ([
                "��": "һ��ټ��Ĵ����������ң�ҡҡ�λε��ƺ�һ�ƾͻ�ɢ�ܣ������壩��\n",
                "bed": "һ��ټ��Ĵ����������ң�ҡҡ�λε��ƺ�һ�ƾͻ�ɢ�ܣ������壩��\n",
                "ټ��Ĵ�": "һ��ټ��Ĵ����������ң�ҡҡ�λε��ƺ�һ�ƾͻ�ɢ�ܣ������壩��\n"
        ]) );
	set("coor/x",10);
	set("coor/y",210);
	set("coor/z",80);
	setup();
}

void init()
{
	add_action("do_move", "move");
}

int do_move(string arg)
{
	object mice;
	if ( !arg && arg != "bed" && arg != "��" && arg != "ټ��Ĵ�")
		return 0;
	if( query("amount") > 5 )
		return 0;
	message_vision("$N�����´���һֻС����ɿ�ش��˳�����\n", this_player());
	mice = new(__DIR__"obj/mouse");
	if(mice) 
		mice->move(this_object());
	add("amount",1);
	return 1;
}

void reset()
{
	::reset();
	set("amount",0);
}