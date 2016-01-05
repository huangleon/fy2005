inherit ROOM;

void create()
{
	set("short", "����ƺ");

	set("long", @LONG
������һ�鷼��ƺ���̲����𣬺������裬�����˱ǣ����˸е�ʮ����⡣��
�����˾���һͷ�ɵ���ȥ���úõ�ȥ˯һ����������ż��Ҳ�������˻��ߡ�������
ƬС���֣����Ǽ����ҡ�
LONG);

	set("type","grassland");
	set("outdoors", "fugui");
	set("exits",([
		"west":__DIR__"grass2",
		"north":__DIR__"woshi1",
		"southwest":__DIR__"shibanlu4",
	]) );
	set("objects",([
		__DIR__"npc/boy" : 1,
		__DIR__"npc/snake" : 1,
		__DIR__"obj/grass" : 1,
       	]) );

	set("coor/x",20);
	set("coor/y",230);
	set("coor/z",80);
	setup();
}

void init()
{
	add_action("do_search", "search");
}

int do_search(string arg)
{
        object me,obj;
        object grass;
        me = this_player();
        grass = present("grass", this_object());

	if(!arg) 
	{
		write("��Ҫ�������Ҷ�����������ʾ�ò��ã��ϴ�\n");
		return 1;
	}
	
	if( me->is_busy() )
        	return notify_fail("����һ��������û����ɣ����ܲ��ҡ�\n");
	
	if( arg == "grass" || arg == "�̲�"  )
        {
		if ( !query("gotit") && ! random(5) )
		{
			message_vision("$N�������ӣ���ϸ�����������������е㶫�������̲��±ߡ�\n",me);
			obj = new(__DIR__"obj/snakeskin");
			obj->move(grass);
			set("gotit",1);
		}
		else
		{
			message_vision("$N���ֲ����ݴԣ���ϸ�Ĳ���һ������ʲô��û���ҵ���\n",me);
			me->start_busy(2);
		}
	}
        else
        {
                write("���Ҳ���"+arg+"��\n");
                return 1;
        }
        return 1;
}

void reset()
{
	::reset();
	if( query("gotit") ) set("gotit",0);
}