// dust.c

inherit COMBINED_ITEM;

void create()
{
        set_name("��ʬ��", ({"dust"}));
        set("long","����һ��������ʬ�𼣵Ļ�ʬ�ۣ�ֻҪ��һ����Ϳ��Ի�ȥһ��ʬ�壡\n");
		set("base_value", 5);
        set("unit", "��");
        set("base_unit", "��");
        set("base_weight", 1);
        set("volumn",1);
        set_amount(1);
}

/*
void init()
{
        if( this_player()==environment() )
                add_action("do_dissolve", "dissolve");
}

int do_dissolve(string arg)
{
        object ob;

        if( !arg ) return notify_fail("��Ҫ�û�ʬ���ܽ�ʲ�ᶫ����\n");
        if( !objectp(ob = present(arg, environment(this_player()))) )
                return notify_fail("����û������������\n");
        if( living(ob) || !ob->id("corpse") )
                return notify_fail("��ʬ��ֻ�������ܽ�ʬ�塣\n");
        message_vision(
                "$N��ָ������һ�㻯ʬ����$n�ϣ�ֻ����һ�����͡��������\n"
                "һ�ɿ��µĶ����$nֻʣ��һ̲��ˮ��\n", this_player(), ob);
        destruct(ob);
        add_amount(-1);
        return 1;
}

*/