inherit ROOM;

void create()
{
	set("short", "����");

	set("long", @LONG
�����Ǹ���ɽׯ��԰һƬ���ܵ���ľ�֣�����һƬ�ž���������ı�ض��ǣ�
����������С·�̳������������̺����֪����Ұ��͵͵�ӹ���С·�Ծ���������
���ʵ�СϪ��Ϫˮ��Ư���������Ҷ������֦Ҷ����ϡ�ɿ���Ϫˮ�����羵���峺
���ס�����·��һ��ʯ�����๸����Լ���Կ�������д�š���Ȫ�����֡�
LONG);
	set("outdoors", "fugui");
	set("type","forest");
	set("exits",([
		"north":__DIR__"senling3",
		"southeast":__DIR__"senling1",
	]) );
        set("item_desc", ([
                "brook": "Ϫˮ�����羵���峺���ף�ż���м�������Ư����ˮ���ϡ�\n",
                "liquan": "Ϫˮ�����羵���峺���ף�ż���м�������Ư����ˮ���ϡ�\n",
                "СϪ": "Ϫˮ�����羵���峺���ף�ż���м�������Ư����ˮ���ϡ�\n",
                "ʯ��": "ʯ���Ѿ������Զ���ưܲ���������Լ���Կ����������[��Ȫ]���֡�\n",
                "stone": "ʯ���Ѿ������Զ���ưܲ���������Լ���Կ����������[��Ȫ]���֡�\n",
                "shibei": "ʯ���Ѿ������Զ���ưܲ���������Լ���Կ����������[��Ȫ]���֡�\n",
        ]) );
//      set("resource/water",1);
        set("liquid/name","��Ȫˮ");
    	set("liquid/type", "water");
     	set("liquid/drunk_apply",0);
	set("coor/x",-20);
	set("coor/y",240);
	set("coor/z",80);
	setup();
	
}


void init()
{
        add_action("do_fillwater", "fill");
}

int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;
        function f;

        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) 
        {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                for (i=0;i<sizeof(list);i++) 
                {
                  if (((string)list[i]->query("liquid/type") == "alcohol") || ((string)list[i]->query("liquid/type") == "water") )
                  {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "��Ȫˮ",
                                "remaining": ob->query("max_liquid"),
                                "drunk_apply": 0,
                        ]) );
				        f = (: call_other, __FILE__, "drink_drug" :);
                    //    ob->set("carrier",1);
                    //    ob->set("fun_carrier",this_object());
                        ob->set("liquid/drink_func", bind(f, ob));
                        write("���СϪ��װ������Ȫˮ�� \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) 
                {
                        write("��û��װˮ�Ķ�����....\n");
                        return 1;
                }
        }
        else 
        {
                write("��Ҫ��ʲô�������ˮ��\n");
        }
        return 1;
}

int drink_drug(object ob)
{
        this_player()->set_temp("fugui_liquan",1);        
        return 0;
}

