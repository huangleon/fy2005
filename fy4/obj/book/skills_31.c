// book.c

inherit ITEM;

void create()
{
    int	i;

    string *names = ({
        "���������š�", "��ȭ�����š�", "���������š�","���������š�",
        "�������ؾ���", "������֮����", "���������š�","���������š�",
        "��ǹ�����š�","���������š�", "���������š�",
    });

    string *skills= ({
        "staff", "unarmed", "sword", "whip","parry", "dodge","hammer","blade","spear","axe","throwing",
    });

    i = random(11);
    set_name( names[i], ({ "book" }));
    set_weight(100);
//  set("no_transfer",1);
    set("unit", "��");
    set("long", "����һ�����������书���鼮��\n");
    set("skill", ([
        "name":                 skills[i],
        "exp_required": 0,                
        "sen_cost":     10,     
        "difficulty":   20,            
        "max_skill":    30           
                                            
        ]) );
	::init_item();
}
