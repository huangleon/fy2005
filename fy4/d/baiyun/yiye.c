//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "һҶ��");
    set("long", @LONG
һҶի�ǰ��Ƶ��ϵ�һ����Ժ��һ����Ⱦ��һλׯ���������������̫ʦ����
��ѧ���Ǿ���Ҷ�Ϸ��������ˡ�������������������ѧ��ѧ����һ�Ź��ⰻȻ����
��������������ǰ�棬���ϰ��ż��������˵���װ�鼮���������£����������
����ʵ�ˢˢ֮����
LONG
    );
    set("exits",
      ([
	"south" : __DIR__"skystreet4",
      ]));
    set("objects",
      ([
	__DIR__"npc/oldye" : 1,
	__DIR__"obj/desk": 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",20);
    set("coor/y",-150);
    set("coor/z",30);
    setup();

}

void reset() {
    int num = 2;
    object obj, *inv ,desk;

    :: reset();

    desk = present("book desk", this_object());
    if (!desk)	return;

    inv = all_inventory(desk);
    foreach (object ob in inv) 
    {
	if (userp(ob)) continue;
	if (ob->query("id") == "ethic book") destruct(ob);
    }
    while (num--) 
    {
	obj = new(BOOKS"skill/daode_30");
	obj->move(desk);
    }
}
