// annie 07.2003
// dancing_faery@hotmail.com

inherit ITEM;

void create()
{
        set_name("��꼷�������", ({ "chanting book","book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "�Ȿ�����ֽ�Ŷ��Ѿ������ˣ����Ǿ������˷��ģ������ƺ�д��\n"
                        "һЩ���ġ�\n");
                set("value", 0);
                set("no_drop",1);
                set("material", "paper");
                set("skill", ([
                        "name":         "chanting",        
                        "exp_required": 100000,                         
                        "sen_cost":     2,                             
                        "difficulty":   20,             
                        "max_skill":    50              
                ]) );
        }
        ::init_item();
}

