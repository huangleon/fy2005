/*Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��һ�ε��������һ����������������ģ��޴��ޱȵı������滷ɽ����Ϊ��
֧����Ϊ��������Χ��ɽѩӳ��[37m����[32m��͸��˵�����Ĺ��졣ԶԶ��ȥ����ֱ����һ
��������������Ůһ�������ų����˶�������Ĺ�ʣ�
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"baiyang",
]));
        set("item_desc", ([
                "����": "��Χ�ű��������ֿ������ֱ������ƺ����ŹŹ֣����������룩������\n",
                "ice": "��Χ�ű��������ֿ������ֱ������ƺ����ŹŹ֣����������룩������\n",
        ]) );
        set("frozen",10);
        //set("no_pk",1);
                
        set("outdoors", "xinjiang");
		set("coor/x",10);
		set("coor/y",-70);
		set("coor/z",0);
		setup();
}

void init()
{
        add_action("do_pour", "pour");
		add_action("do_break", "break");
}

int do_pour(string arg)
{
        object me;
        object con;
        me = this_player();
        if(!arg) return 0;
        if(!objectp(con=present(arg, me)))
        return 0;
        if(!con->query("liquid"))
        return 0;
        if(!con->query("liquid/remaining"))
        	return notify_fail( con->name() + "�ǿյġ�\n");
        con->add("liquid/remaining", -1);
        message_vision("$N����" + con->name() + "����һЩ" +
        	con->query("liquid/name")  + "�ں����ϡ�\n",me);
        if(con->query("liquid/name") == "��ˮ")
        	tell_object(me,"�����ոջ�����һ������ֶ����ˣ���\n");
        if(con->query("liquid/name") == "��ˮ")
        {
        	tell_object(me,"��ֵúܣ�����һ����ˮ�Ϳ�ʼ�ⶳ�ˣ���\n");
        	add("frozen",-1);
        }
        if( query("frozen") <= 0 )
        {
        	tell_object(me,"�������ڻ�����һ��С��������\n");
        	if(!query("exits/southwest"))
                set("exits/southwest",__DIR__"gela");
        	call_out("close_path",10);
        }
        return 1;
}

void close_path()
{
        if( !query("exits/southwest") ) return;
        message("vision",
"Ʈ������ˮ��գ�ۼ䶳�ɱ��飬�����ط�ס�˶��ڣ���\n",
                this_object() );
        delete("exits/southwest");
        set("frozen",30+random(5));
}

int do_break()
{
		object me;
		me = this_player();
		if(me->query("force") < 50)
			return notify_fail("������������ˣ�\n");
		me->add("force",-50);
			return notify_fail("�����һ�ƣ����صػ��ڱ����ϣ�ɲ�Ǽ��м��ɣ������ϵ��Ѻ۸����ˣ�\n");
}



