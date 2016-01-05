inherit ROOM;
void close_path();

void create()
{
    set("short", "�����Ÿ�");
    set("long", @LONG
����ר���д���������������������������������ģ�����һ��ǧ��ĺ�
�ͣ����Ƕ��Ž����Ĳ���һ�����������䷿�ӵ�����ֻ��һ���ϵȴ����ĥ�ɵ�
�����������Ϸ�����ֻ���ͽ𱭡������ǽ�Ϲ������ֻ���ʣ�µ�һ����һ��һ��
���ص�[33m�첼����[32m��
LONG
    );
    set("exits", ([
	"down" : __DIR__"fyge",
	"east" : __DIR__"fysf",
      ]));
    set("objects", ([
				__DIR__"npc/servant": 1,
				__DIR__"npc/tatoo": 1,
	//			AREA_GUANWAI"npc/champion": 1,

      ]) );
    set("item_desc", ([
	"curtain": "����첼�����ƺ������ƿ�(open)��\n",
	"����" : 	"����첼�����ƺ������ƿ�(open)��\n",
	"�첼����" : "����첼�����ƺ������ƿ�(open)��\n"
      ]) );
//    set("NONPC",1);
    set("coor/x",40);
    set("coor/y",40);
    set("coor/z",10);
    setup();
}

void init()
{
    add_action("do_open", "open");
}

void close_path()
{
    if( !query("exits/north") ) return;
    message("vision","�첼������������������ס�˰��š�\n",this_object() );
    delete("exits/north");
}


int do_open(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg=="" ) return 0;

    if( arg=="curtain" || arg =="�첼����" || arg=="����") {
	write("���ƿ��첼������");
	if( (int) me->query("force_factor") >= 100 )	{
	    write("�ƿ��˺����򱱵�һ�Ȱ��š�\n");
	    if( !query("exits/west") ) {
		set("exits/north", __DIR__"fysecret");
		call_out("close_path", 5);
	    }
	    return 1;	
	}	else
	    write("���������ƺ���İ��ţ���û���ƿ���\n");
	return 1;
    }
    write("��Ҫ�ƿ�ʲô��\n");
}



void init_scenery()
{
    object tie;
    tie = present("royal servant", this_object());
    if (tie) {        
	if (tie->query("in_meihuadao")) {
	    tie->delete("in_meihuadao");
	    tie->delete("no_heal");
	    return;
	} else {
	    CHANNEL_D->do_sys_channel("info",sprintf("%s��������׷Ϯ÷����δ�������һ������˶��顣", NATURE_D->game_time()));
	    tie->set("in_meihuadao",1);
	    tie->set("eff_kee",tie->query("max_kee")/2);
	    tie->set("eff_gin",tie->query("max_gin")/2);
	    tie->set("eff_sen",tie->query("max_sen")/2);
	    tie->set("no_heal",1);
	}
    }
    return;	
}

