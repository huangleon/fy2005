inherit __DIR__"no_killing_place";
void create()
{
        set("short", "ũ��");
        set("long", @LONG
����һ���ܼ��ӵ�ũ�ң��ų����ţ����ڳ���ʮ�ּ򵥣����Ҿ����ĵģ�����
�����ȥ�����ˡ������������ż򵥵ı��죬�������һ���Ѿ��ܾ��˵���������
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  	"west" : __DIR__"nongjia",
	]) );

   	set("objects", ([
      		__DIR__"obj/basket": 1,
   	]) );

	set("no_magic", 1);
	set("coor/x",15);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void reset()
{
	object *inv;
        object item1, item2, item3, basket;
        int i, needle, thread;
        
        ::reset();
        basket = present("basket", this_object());
        inv = all_inventory(basket);
        for (i=0;i<sizeof(inv);i++) {
        	if (inv[i]->query("name")=="�廨��") needle=1;
        	if (inv[i]->query("name")=="ϸ����") thread=1;
        }
        if (!needle) {
        	item1 = new(__DIR__"obj/needle");
        	item1->move(basket);
        	}
        if (!thread) {
        	item2 = new(__DIR__"obj/string");
        	item2->move(basket);
        	}
}
