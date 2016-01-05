inherit ROOM;

void create()
{
	set("short", "����԰");

	set("long", @LONG
�����������������ܾ��Ǵ���԰��������������ÿ�������°׵���ҹ������
ɽׯ�����������Ǳ�����ˣ�һ�����Σ�һ����裬���Ǻ��˰������������ϧ��
���ܾ��Ѿ�û��������ˣ����ǻ�ʱ���������ֵ��ǿ�����Ǯ���ƣ��긴һ�꣬��
��԰�е�����ҲԽ��Խ�١�
LONG);
	set("outdoors", "fugui");
	set("type","forest");
	set("exits",([
		"north":__DIR__"wuzhuxuan",
	]) );
	
	set("item_desc", ([
                "bamboo": "������������ҡ�ڣ����ƺ������ۣ�pick������������\n",
		"����": "������������ҡ�ڣ����ƺ������ۣ�pick������������\n",
        ]) );
	set("coor/x",-10);
	set("coor/y",200);
	set("coor/z",80);
	setup();
}

void init()
{
	add_action("do_pick","pick");
}

do_pick(string arg)
{
	object bamboo;
	if ( !arg && arg != "bamboo" && arg != "����" )
		return notify_fail("��Ҫ��ʲô��\n");
	if((int) query("picked") <= 3)
	{
		write("������һ����������ӣ�С�ĵķ��ڻ��\n");
		bamboo = new("/d/taoyuan/obj/bamboo");
		bamboo->move(this_player());
		add("picked",1);
		return 1;
	}
	else
        write("�����Ѿ������۹��ˣ���\n");
        return 1;
}

void reset()
{
	:: reset();
	delete("picked");
}