inherit __DIR__"no_killing_place";
void create()
{
        set("short", "��ȳ�");
        set("long", @LONG
�����Ĵ�ȳ��Ͼ��ȵ�����һ��Ƴγεĵ���������һ�����Ƶ���Ȼ����ڿ�
�ǿ��ǵ�ת�ţ�����ũ�˶�����������һ�߳Է�������ʱ��ע���ŷ�ֹ��ȸ��͵�Թ�
��������ȳ����Ϸ��ż����Ѿ������˵���Ϳ��ӡ�
LONG
        );

    set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"nongjia1",
	]) );

    set("objects", ([
    	__DIR__"obj/bowl": 1,
       	__DIR__"npc/farmer":3,
    ]) );
	set("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",10);
	set("coor/y",30);
	set("coor/z",0);
	setup();
}


void reset()
{
        object *inv;
        object item1, bowl;
        ::reset();
        bowl = present("bowl", this_object());
        inv = all_inventory(bowl);
        if( !sizeof(inv)) {
        item1 = new(__DIR__"obj/fishbone");
        item1->move(bowl);
        }
}

