inherit __DIR__"no_killing_place";
void create()
{
    set("short", "СԺ");
    set("long", @LONG
СС��Ժ�䣬����һ�����Ѽ���ס�˰�ߣ�����бб���������棬�����̵�Ҷ
�����͸����һ�������㶹��һЩ�����Ѿ�Ө��͸����ʵ�һ����һ��СС��ľ�
������������ţ�����ķ��䴫�����󷹲��㡣
LONG
        );
    set("exits", ([ 
	"east" : __DIR__"kitchen",
	"north" : __DIR__"livingroom",
	"west" : __DIR__"cyard1",
	]) );

    set("objects", ([
	__DIR__"obj/storage": 1,
	]) );
	
	set("item_desc", ([
		"door" : "������̵Ĳ���ֻ�������ţ��ƺ�����һ�ƾͿ��ˡ�\n",
		"����" : "������̵Ĳ���ֻ�������ţ��ƺ�����һ�ƾͿ��ˡ�\n",
	]) );

    set("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",20);
	set("coor/y",20);
	set("coor/z",0);
    setup();
}


void init() {
	::init();
	add_action("do_push", "push");
} 

void close_path()
{
	if( query("exits/south") ) {
    message("vision","�������ص��˼�����������ھ�ֹ�ˡ�\n",this_object() );
    delete("exits/south");
    }
}

int do_push(string arg)
{
	object me;
    me = this_player();
    if( arg=="door" || arg =="����") {
    	message_vision("$N�������������һ�ƣ�֨��������һ�����ſ��ˡ�\n", me);
		set("exits/south", __DIR__"anju");
		call_out("close_path", 5);
	}
	else {
		write("��Ҫ��ʲô�أ�\n");
	}
	return 1;
}

void reset()
{
    int i;
    object *inv;
    object item1, item2, storage ;
    ::reset();
    storage = present("storage", this_object());
    inv = all_inventory(storage);
    for(i=0;i<sizeof(inv);i++)
        destruct(inv[i]);
    item1 = new(__DIR__"obj/saoba");
    item1->move(storage);
    item2 = new(__DIR__"obj/gao");
    item2->move(storage);
}
