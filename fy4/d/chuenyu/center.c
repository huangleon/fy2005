
inherit ROOM;

void create()
{
        set("short", "���ɸ�����");
        set("long", @LONG
���ɸ�������ȫ����̴��ľ����ġ�һ�����̴��Ʈ������
ʹ���Ŀ����ġ���������һ���ֻ���д�������Ƿǳɰ�תͷ�գ�
��ɽ�����ڣ�����Ϧ���졣�������ֻ�����һ���ֵܴ����ӹ���
���ġ�
LONG
        );
        set("exits", ([
	"west" : __DIR__"west_blackge",
        ]));
        set("item_desc", ([
                "rope": "�������˳��ǽ�����������ƺ�������(pull)������������һ�ֲ���ĸо���\n",
		"����": "�������˳��ǽ�����������ƺ�������(pull)������������һ�ֲ���ĸо���\n",
        ]) );


	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",20);
	setup();
}

void init()
{
	add_action("roping", "pull");
}

int roping(string arg)
{
	int i;
	int damage;
	object obj;
	object ob;
	object me;
	ob = this_player();
	if(!arg || arg=="")
	{
		write("��Ҫ��ʲô��\n");
		return 1;
	}
	if( arg == "rope" || arg == "����" )
	{
	me = this_player();
        message_vision("$N��������һ�����ӣ������˷��壬�����ˡ���¡��һ��������ȥ��\n", me);
        me->move(__DIR__"tunnel1");
        message_vision("$N����¡��һ�������������������ˤ��$N��ʹ��\n", me);
	i = (int)ob->query("eff_kee");
        damage = random(10)+5  ;
        ob->set("eff_kee",(int) i - damage );
        i =  (int)ob->query("kee");
        ob->set("kee",(int) i - damage);

        return 1;
	}
	else
	{
		write("�㲻������"+arg+"\n");
		return 1;
	}
}
