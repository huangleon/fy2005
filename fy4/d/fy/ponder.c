inherit ROOM;
void create()
{
    set("short", "ϴ���");
    set("long", @LONG
����ɳ��ս����ף�����¥���ղ����������Ƴ���Ĺٱ�����������ս������
�����ǻ�������ϴ�񣨣�������壩������ϴȥɱ��֮���ĵط������õúܼ򵥣�
ټ���һ�����ӣ��м�һ��ˮ�أ�����ð������������
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"nwind1",
	"north" : __DIR__"byroom",
      ]));
    set("outdoors", "fengyun");
    set("coor/x",40);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fynorth");
    setup();
}

void init()
{
    add_action("do_ponder","salute");
}


int do_ponder(string arg)
{
    object who;

    who = this_player();
    if((int) who->query("sen") <= 200)
		return notify_fail("����񲻹���������Ҫ�������㡣\n");
    
    message_vision("$N��˫�ֽ���ˮ���С�\n" ,who);
    who->receive_damage("sen",200);
    
    if(who->query("bellicosity") > 0)
		who->add("bellicosity", - (random((int)who->query("kar"))*6 + 50 ) );
    
    if (who->query("bellicosity")<0)
    	who->set("bellicosity",0);
    
    message_vision("$N���ϵ�ɱ��֮���ƺ����ˡ� \n" , who);
    
    return 1;
}

