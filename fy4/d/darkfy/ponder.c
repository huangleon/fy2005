inherit ROOM;
void create()
{
        set("short", "ϴ���");
        set("long", @LONG
�����Ƿ��Ʊ�����ս��������ϴ�񣨣�������壩�ĵط���
����ϴȥɱ��֮�������õúܼ򵥣��м�һ��ˮ�أ�����ð����
��ˮ�Ρ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"ecloud4",
]));
        set("outdoors", "fengyun");
        set("coor/x",40);
        set("coor/y",-10);
        set("coor/z",-300);
        setup();
}

       object who;

       who = this_player();
        if((int) who->query("sen") <=50)
        return notify_fail("����񲻹���\n");
       message_vision("$N��˫�ֽ���ˮ���С�\n" ,who);
       who->receive_damage("sen",50);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 7 ) );
       message_vision("$N���ϵ�ɱ��֮���ƺ����ˡ� \n" , who);
    return 1;
}

