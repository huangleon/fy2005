inherit __DIR__"no_killing_place";
void create()
{
    set("short", "����");
    set("long", @LONG
�ߴ����ľΪ����ȡ����������Ŭ��������չ�ţ�����������͸�����ڣ���
�Լ�ʹ�ǰ�������Ҳ�Եúܻ谵���������泤���˲�֪���İ�С��ֲ���������
���˸�ʽ���������ܣ��еĻ��������޵Ļ��䡣
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"linjian",
        "east" : __DIR__ "forest",
        ]));

    set("outdoors","taoyuan");
    set("item_desc", ([
        "����":"�����������ϵ����ܳ���ʮ��ïʢ�����ܵ�Ƥ���Ͷ���ʵ��\n"
          "������õ���������𡡣����壩��\n",
        "vine":"�����������ϵ����ܳ���ʮ��ïʢ�����ܵ�Ƥ���Ͷ���ʵ��\n"
          "������õ���������𡡣����壩��\n",
	]) );
    set("no_magic", 1);
	set("coor/x",20);
	set("coor/y",-10);
	set("coor/z",0);
    setup();
}

int do_cut(string arg)
{
    object obj;
    object me;

    if(arg && (arg=="vine" || arg=="����"))
    {
	me = this_player();
	obj = me->query_temp("weapon");
	if( !obj ) 
	{
            write("������֣���ô����\n");
            return 1;
	}
	if( obj->query("flag") == 4)
	{
            if(!query("marks/gone"))
            {
                object ob;
                message_vision(sprintf(
                    "$N�Ӷ�%s��������һ�����������ܡ�\n",obj->name()),me);
                set("marks/gone",1);
                ob=new(__DIR__"obj/tengluo");
                ob->move(me);
            }
            else message_vision(sprintf(
            "$N�����е�%sһ���ҿ������������Ѿ������ò���ˡ�\n",obj->name()), me);
	}
	else message_vision(sprintf(
            "$N�����е�%s�����������һ���ҿ�������%s̫�������ˣ�ʲôҲû��������\n",obj->name(),obj->name()), me);
    }
    else write("��Ҫ����ʲô��\n");
    return 1;
}

void init()
{
	::init();
    add_action("do_cut","chop");
}

void reset()
{
    ::reset();
    delete("marks/gone");
}
