inherit ITEM;

void create()
{
        set_name("��̤������ͼ��", ({ "painting"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�������ӵġ�̤������ͼ����������̤��ɫ���е����湫�ӳ���˧��\n");
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

        tell_object(me,"һ�������ӵġ�̤������ͼ����������̤��ɫ���е����湫�ӳ���˧��\n�ڷ�������ܻ�ӭ����˼۸�Ҳ�ڽڰθߡ�\n");

        if (me->query("gender") == "����")
        {
                message("vision", me->name() + "չ��һ��" + ob->name() + "����м������һ���������������\n��С������ʲô��Ӣ�����������ٷ�ı����ӿɱ���˧���ˡ�\n", environment(me), me);
                tell_object(me,"��չ��������һ�ۣ���м������һ�����������С������ʲô��Ӣ�����������ٷ�ı����ӿɱ���˧���ˡ�\n");
                return 1;
        }
        
   switch( random(3) ) {
                        case 0:
        message("vision", me->name() + "������" + ob->name()
                        + "����������������£�ڻ��\n", environment(me), me);
                                        break;
                        case 1:
        message("vision", me->name() + "��͵͵���������" + ob->name()
                        + "һ�ۣ��۹��ɵ���롣\n", environment(me), me);
                                        break;
                        case 2:
        message("vision", me->name() + "չ��" + ob->name()
                        + "�ḧ�����Ϸ���һĨ���Ρ�\n", environment(me), me);
                                        break;
        }
        message("vision", me->name() + "�����ĶԻ�ɵЦ�����η��⡣\n", environment(me), me);
        write("\n��е���ͷ��ֻС¹��ײ�����飢�����飢�����飢������\n");
        me->unconcious();
        return 1;
}

