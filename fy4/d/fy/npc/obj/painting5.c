inherit ITEM;

void create()
{
        set_name("�����˳�ԡͼ��", ({ "painting"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�������ӵġ����˳�ԡͼ�����������ϵ���֮����������֮����\n");
                set("value", 50000);
        }
        ::init_item();
}


void init()
{
        if(this_player()==environment())
                add_action("do_look","look");
}

int do_look(string arg)
{
    object me,ob;
    me = this_player();
        if (!arg)
                return 0;
        ob = present(arg,me);
        if (!ob)
                return 0;
        if (ob != this_object())
                return 0;

        tell_object(me,"һ�������ӵġ����˳�ԡͼ�����������ϵ���֮����������֮����\n���ڷ�����ƫ���кܶ���ϲ������˼۸�Ҳ�ڽڰθߡ�\n");

        if (me->query("gender") == "Ů��")
        {
                message("vision", me->name() + "չ��һ��" + ob->name() + "����ʱ�ߵ�����ͨ�졣\n", environment(me), me);
                tell_object(me,"��չ��������һ�ۣ��ߵ�����ͨ�죬��æ��£��������\n");
                return 1;
        }
        
   switch( random(3) ) {
                        case 0:
        message("vision", me->name() + "����ϲ�����������" + ob->name()
                        + "��\n", environment(me), me);
                                        break;
                        case 1:
        message("vision", me->name() + "���ҿ���" + ob->name()
                        + "��̧��ͷ��ɫ���������������µĴ������㡣\n", environment(me), me);
                                        break;
                        case 2:
        message("vision", me->name() + "չ��" + ob->name()
                        + "�ḧ����ž����һ����һ�ο�ˮ���ڻ��ϡ�\n", environment(me), me);
                                        break;
        }
        write("��е�һ�������ӵ���ֱ�����𣮣���\n");
        me->unconcious();
        return 1;
}

