inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������û�б����ɫ��ֻ�кڣ���Ϧ���ս����������һ�ֲ����������ɫ��
��ɫ����ᣵʹ���û�����ܿ��ü����湩�����ʲô�����������аѵ�������
��ڣ�������ڡ���������һ�����ӣ�sign������������һ������look sign����
LONG
        );
        set("exits", ([ 
  		"northwest" : __DIR__"sichou5",
           	"southeast" : AREA_QUICKSAND"skyroad3",
	]));
        set("item_desc", ([
                "sign": @TEXT

			�Ӵ�����������ͼɱ��������

������������С�֣����˴������������������KILL�Ķ����ܵ�������˫ӥ��
��Χɱ����������������ǩ����
			�ϳ��ӥ ������
        		˫ͷͺӥ ����ľ
TEXT,
                "��": "������ز��ڵ����У�ֻ¶����ڵĵ���������������ز������С�\n",
		"blade" : "������ز��ڵ����У�ֻ¶����ڵĵ���������������ز������С�\n",
        ]) );
        set("objects", ([
//	        __DIR__"npc/furen" : 1,
        ]) );
        
        
	set("NONPC",1);
        set("valid_startroom", 1);
	set("coor/x",120);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
}

/*
void init()
{
	add_action("do_shake","shake");
}
int do_shake(string arg)
{
	object ob;
	if(arg == "��" || arg == "blade")
	{
	message_vision("$Nץס��ڵĵ���������ҡ��ҡ��\n",this_player());	
	if(ob=(present("old woman",this_object())))
		message_vision("$N����$nһ�ۣ������ã�����ұ��𣿣�ȥɱ���Ǹ������������ˣ�\n",ob,
		this_player());
	return 1;
	}
	else
	return 0;

}
*/