// sinny@fengyun
inherit ITEM;
void create()
{
        string *names = ({
                "����ӹ��", "������֮����ƪ��", "������֮Ȱѧƪ��",
                "������֮���ƪ��", "��Т����"
        });

        set_name( names[random(sizeof(names))], ({ "ethic book","book" }));
        set_weight(600);
        set("unit", "��");
        set("long", "����֪����������ѧ�߳��������ص伮��\n");
        set("value", 100);
        set("skill", ([
                "name":         "daode", 
                "exp_required": 5000,    
                "sen_cost":     15,      
                "difficulty":   30,                                              
                "max_skill":    29       
        ]) );
}
