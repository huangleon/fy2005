inherit ROOM;

void create()
{
    set("short", "�ھֳ���");
    set("long", @LONG
��ʨ�ھֶԻ����ʮ�ֿ��������ÿ����н�𣬶��һ�����ס��������ǻ��
��һ�����͵ĵط���������ǽ�Ϲ����˹���ư�裬����һЩ��ɵ�±ζ�������з�
��һ��[33m��̨[32m����̨����Χ���ż���[33m����[32m�����������У���������æ�ò��ɿ�����
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"northeast" : __DIR__"goldlion",
      ]));
    set("objects", ([
	__DIR__"npc/goldcook" : 1,
	__DIR__"obj/wall": 1,

      ]) );

    set("coor/x",140);
    set("coor/y",-80);
    set("coor/z",0);
    set("map","fyeast");
    setup();

}

void init(){
    add_action("do_look","look");
}


int do_look(string arg){

    if (arg == "table")	arg = "��̨";
    if (arg == "stool")	arg = "����";

    if (arg == "��̨" || arg == "����") {
	if (!this_player()->query_temp("marks/js_cook_mice")) {
	    tell_object(this_player(),"����һ�ź���ͨ��"+ arg + "������մ�������̡�\n");
	    return 1;
	}
	tell_object(this_player(),"���һ������ŷ��֣����������϶��������ܹ��ĺۼ���һֱ���쵽Ժ���\n");
	this_player()->set_temp("marks/js_cook_mice",2);
	return 1;
    }
    return 0;
}

void reset()
{
    object          *inv;
    object          con, item;
    int             i;

    ::reset();
    con = present("wall", this_object());
    inv = all_inventory(con);
    if( sizeof(inv) != 1) {
	for(i=sizeof(inv)-1; i>=0; i--)destruct(inv[i]);
	if (item = new(__DIR__"npc/obj/luwei")) {
	    if (!item->move(con))
		destruct(item);
	}
    }
}
